// Author : Sarthak Kapoor
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define rep(i,n) for(int i=0;i<n;++i)
#define repa(i,a,n) for(int i=a;i<n;++i)
#define repr(i,n) for(int i=n-1;i>=0;--i)
#define repba(i,b,a) for(int i=b;i>=a;--i)
#define repab(i,a,b) for(int i=a;i<b;++i)
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define msi map<string,int>
#define mii map<int,int>
#define viip vector<pair<int,pair<int,int> > > 
#define mp make_pair
#define vip vector<pair<int,int> >
#define pb push_back 
#define po pop_back
#define fi first
#define sec second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define s(v) v.size()
ll mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//use rng()%n for numbers in range [0,n-1]
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
const ll inf = 1e17;
const int maxn = 1e5+2;
vi v[maxn];
bool vis[maxn];
ll dp[maxn][3];
void dfs(int u){
	vis[u] = true;
	for(auto x:v[u]){
		rep(i,3){
			if(dp[u][i] != inf){
				// if(dp[x][(i+1)])
				dp[x][(i+1)%3]=min(dp[u][i]+1ll,dp[x][(i+1)%3]);
			}
		}
		if(!vis[x]){
			dfs(x);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;
	int m;
	cin>>m;
	rep(i,m){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
	}
	int s,t;
	cin>>s>>t;
	rep(i,maxn){
		rep(j,3){
			dp[i][j] = inf;
		}
	}
	dp[s][0] = 0ll;	
	rep(j,20){
		rep(i,maxn)vis[i]=false;
		dfs(s);
	}
	// dfs(s);
	
	// rep(i,maxn)vis[i]=false;
	// dfs(s);
	// repa(i,1,7){
	// 	rep(j,3){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	if(dp[t][0] != inf){
		cout<<dp[t][0]/3;
	}
	else{
		cout<<-1;
	}
	return 0;
}