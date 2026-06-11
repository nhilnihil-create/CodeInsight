#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const int inf = (1LL<<31) -1;
const ll MAXN = 200000;
const ll MAXD = 1000000;

string S;
ll N, M, ans=0, tmp=0;

struct segmentTree{
	vector<int> node;
	int n;
	
	segmentTree(vector<int> &v){
		int s = v.size();
		n = 2;
		while(n < s) n *= 2;
		node = vector<int>(2*n -1, inf);
		for(int i=0; i<s; i++){
			node[i +n-1] = v[i];
		}
		for(int i=n-2; i>=0; i--){
			node[i] = min(node[2*i +1], node[2*i +2]);
		}
	}
	
	void Set(int val, int pos){
		int idx = n-1 + pos;
		node[idx] = val;
		do{
			idx = (idx -1)/2;
			node[idx] = min(node[2*idx +1], node[2*idx +2]);
		}while(idx != 0);
	}
	int Get(int l, int r){
		return _get(l, r, 0, 0, n);
	}
	int _get(int l, int r, int k, int cl, int cr){
		if(l <= cl && cr <= r){
			return node[k];
		}
		if(r <= cl || cr <= l){
			return inf;
		}
		int m = (cl +cr)/2;
		return min(_get(l, r, 2*k+1, cl, m), _get(l, r, 2*k+2, m, cr));
	}
};

void DPinit() {
    vector<ll> A, DP(N+1, MAXD), Pre(N+1, 0);
    DP[0]=0;
    segmentTree segtree(DP);
    for(int i=1;i<=N;i++) {
        if(S[i]=='0') {
            ll a;
            if(i<M) a=segtree.Get(0, i);
            else a=segtree.Get(i-M, i);
            segtree.Set(a+1, i);
        }
    }
    
    ll c = segtree.Get(N, N+1);
    if(c>=MAXD) {
        cout << -1 << endl;
        return;
    }

    ll id=N;
    while(id!=0) {
        for(int i=M;i>=1;i--) {
            if(id-i>=0) {
                ll e = segtree.Get(id-i, id-i+1);
                ll f = segtree.Get(id, id+1);
                if(e==f-1) {
                    A.push_back(i);
                    id = id-i;
                    break;
                }
            }
        }
    }

    for(int i=A.size()-1;i>=0;i--) {
        cout << A[i] << endl;
    }
}

signed main(){
    cin >> N >> M >> S;
    DPinit();
    return 0;
}