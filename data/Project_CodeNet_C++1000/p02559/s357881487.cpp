#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int N = 5e5 + 10;
//credit : ashish gupta
struct BIT{
	int N;
	vector<int> bit;
 
	void init(int n){
		N = n;
		bit.assign(n + 1, 0);
	}
 
	void update(int idx, int val){
		while(idx <= N){
			bit[idx] += val;
			idx += idx & -idx;
		}
	}
 
	void updateMax(int idx, int val){
		while(idx <= N){
			bit[idx] = max(bit[idx], val);
			idx += idx & -idx;
		}
	}
 
	int pref(int idx){
		int ans = 0;
		while(idx > 0){
			ans += bit[idx];
			idx -= idx & -idx;
		}
		return ans;
	}
 
	int rsum(int l, int r){
		return pref(r) - pref(l - 1);
	}
 
	int prefMax(int idx){
		int ans = -2e9;
		while(idx > 0){
			ans = max(ans, bit[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
};
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    BIT bt;
    bt.init(n+1);
    int v[N];
    for(int i = 1;i <= n;i++){
    	cin >> v[i];
    	bt.update(i,v[i]);
    }
    while(q--){
    	int ty;
    	cin >> ty;
    	if(ty == 0){
    		int id,val;
    		cin >> id >> val;
    		id++;
    		bt.update(id,val);
    	}
    	else{
    		int l,r;
    		cin >> l >> r;
    		l++;
    		cout << bt.rsum(l,r) << "\n";
    	}
    }
    return 0;
}
 