#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

struct SegmentTree{
	private:
		int n;
		vector<int> node;

	public:
		SegmentTree(vector<int> v){
			int sz = v.size();
			n = 1;while(n < sz)n *= 2;
			node.resize(2 * n - 1,INF);

			for(int i = 0; i < sz; i++) {
				node[i + n - 1] = v[i];
			}
			for(int i = n - 2; i >= 0; i--) {
				node[i] = min(node[2 * i + 1],node[2 * i + 2]);
			}
		}

		void update(int x, int val){
			x += n - 1;
			node[x] = val;
			while(x > 0){
				x = (x - 1) / 2;
				node[x] = min(node[2 * x + 1],node[2 * x + 2]);
			}
		}
		//要求区間[a,b)中の要素の最小値
		int getmin(int a,int b,int k = 0,int l = 0,int r = -1){
			if(r < 0)r = n;
			if(r <= a || b <= l)return INF;
			if(a <= l && r <= b)return node[k];

			int vl = getmin(a, b, 2 * k + 1, l, (l + r) / 2);
			int vr = getmin(a, b, 2 * k + 2, (l + r) / 2, r);
			return min(vl,vr);
		}
		void print(){
			for(int i = n - 1; i < 2 * n - 1; i++) {
				cout << i - n - 1 << " " << node[i] << endl;
			}
		}

};

int main(){
	int n,m;cin>>n>>m;
	string s;cin>>s;
	vector<int> x(n + 2,-1);
	SegmentTree seg(vector<int> (n + 2,INF));
	seg.update(n,0);
	for(int i = n - 1; i >= 0; i--) {
		if(s[i] == '1')continue;
		int t = seg.getmin(i + 1,min(n + 1,i + m + 1));
		seg.update(i,t + 1);
	}
	// seg.print();
	vector<int> dist;
	for(int i = 0; i <= n; i++) {
		dist.pb(seg.getmin(i,i + 1));
	}
	int pos = dist[0];
	int tmp = 1;
	vector<int> ans;
	if(pos >= INF){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		if(pos > dist[i]){
			ans.pb(tmp);
			pos = dist[i];
			tmp = 1;
		}
		else{
			tmp++;
		}
	}
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

	
	return 0;
}