// @Author :- Gaurav Bharti
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define empb emplace_back
#define mp make_pair
#define F first
#define S second
#define vii vector<int>
#define vbl vector<bool>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define mapii map<int,int> 
#define mapll map<ll,ll>
#define lcm(a,b) a*b/(__gcd(a,b))
#define all(a) a.begin(),a.end()
#define test int t; cin>>t; while(t--)
#define prec(n) fixed<<setprecision(n)
#define ItsFUN ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007

struct unionFind {
	vii par;
	unionFind(int n): par(n, -1) {}

	void init(int n) {
		par.assign(n, -1);
	}
	
	int root(int x) {
		if(par[x] < 0) {
			return x;
		}
		else return par[x] = root(par[x]);
	}	

	bool isSame(int x, int y) {
		return root(x) == root(y);
	}

	bool merge(int x, int y) {
		x = root(x);
		y = root(y);

		if(x == y) return false;

		if(par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	int size(int x) {
		return - par[root(x)];
	}
};

int main() {
   	ItsFUN;

   	int n, m; cin >> n >> m;
   	unionFind ob(n);

   	for(int i = 0; i<m ;++i) {
   		int x, y; cin >> x >> y;
   		--x, -- y;
   		ob.merge(x, y);
   	}

   	set<int> v;

   	for(int i = 0; i < n; ++i) {
   		v.insert(ob.root(i));
   	}

   	cout << v.size() - 1 << "\n";


   	return 0;
}