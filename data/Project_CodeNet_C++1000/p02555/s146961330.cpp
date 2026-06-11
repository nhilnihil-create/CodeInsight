// Author : Sarthak Kapoor
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int ll
#define rep(i,n) for(int i=0;i<n;++i)
#define repa(i,a,n) for(int i=a;i<n;++i)
#define repr(i,n) for(int i=n-1;i>=0;--i)
#define ll long long
#define pi pair<int,int> 
#define pii pair<pi,int>
#define vi vector<int>
#define pb push_back 
#define fi first
#define sec second
#define all(v) v.begin(),v.end()
#define s(v) v.size()
ll mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//use rng()%n for numbers in range [0,n-1]
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
ll fastexp(ll x,ll a){
    ll res = 1;
    while(a>0){
        if(a&1){
            res = (res*x)%mod;
        }
        a=a>>1;
        x=(x*x)%mod;
    }
    return res;
}
ll inverse(ll n){
    return fastexp(n,mod-2);
}
template <typename T>
void add(T &a, T b){
	a += b;
	if(a >= mod)a -= mod;
}
template <typename T>
void sub(T &a, T b){
	a -= b;
	if(a < 0)a += mod;
}
template <typename T>
void mul(T &a, T b){
	a *= b;
	if(a >= mod)a %= mod;
}
int dp[2001][2001];
int pre[2001][2001];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int s;
	cin>>s;	
	repa(i,3,s+1){
		dp[0][i] = 1;
		add(pre[0][i],dp[0][i]);
		add(pre[0][i],pre[0][i-1]);
	}
	repa(i,1,s+1){
		repa(j,3,s+1){
			add(dp[i][j],pre[i-1][j-3]);
			// add(dp[])
		}
		repa(j,3,s+1){
			add(pre[i][j],dp[i][j]);
			add(pre[i][j],pre[i][j-1]);
		}
	}
	int ans = 0;
	rep(i,s+1){
		add(ans,dp[i][s]);
	}
	cout<<ans;
	return 0;
}
