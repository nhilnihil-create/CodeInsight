#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//typedef __int128 l2;
//typedef long long l2;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef tuple<db,db,db> tdb;
typedef tuple<ll,ll,ll> tll;
typedef tuple<int,int,int,int> ti4;
typedef tuple<db,db,db,db> td4;
typedef vector<vector<ll>> mat;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //shuffle(a+1,a+1+n,rng)
uniform_int_distribution<> gen(1,100); //gen(rng)
const ll mod=1e9+7,inf=1e15;
const int N=5e5+5,M=1e5+5,K=1e5+5;
int n,m,a[N];
vector<int> cur;
multiset<int,greater<int>> st;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n; m=1<<n;
	for(int i=1;i<=m;i++) cin>>a[i];
	sort(a+1,a+1+m); reverse(a+1,a+1+m);
	cur.emplace_back(a[1]);
	for(int i=2;i<=m;i++) st.emplace(a[i]);
	for(int t=1;t<=n;t++){
		vector<int> N;
		for(auto x : cur){
			auto it=st.upper_bound(x);
			if(it!=st.end()){
				N.emplace_back(*it); st.erase(it);
			}
			else{
				cout<<"No"; return 0;
			}
		}
		for(auto x : N) cur.emplace_back(x);
		sort(cur.begin(),cur.end());
	}
	cout<<"Yes";
	return 0;
}