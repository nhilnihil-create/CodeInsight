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
#define pi pair<int,int> 
#define pii pair<pi,int>
#define ull unsigned long long
#define vi vector<int>
#define viip vector<pair<int,pair<int,int> > > 
#define mp make_pair
#define vip vector<pair<int,int> >
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
const int N = 12;
const int maxn = 1e3 + 2;
ll dp[(1<<N)][maxn];
int a[maxn];
ll val[maxn];
int b[maxn];
const ll inf = 1e15;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	rep(i,(1<<n)){
		rep(j,m){
			dp[i][j] = inf;
		}
	}
	rep(j,m){
		dp[0][j] = 0;
	}
	rep(i,m){
		cin>>a[i]>>b[i];
		int mask = 0;
		rep(j,b[i]){
			int c;
			cin>>c;
			c--;
			mask += (1<<c);
		}
		val[i] = mask;
	}
	rep(i,m){
		rep(mask,(1<<n)){
			int sub = 0;
			rep(j,n){
				if(mask & (1<<j)){
					if(!(val[i] & (1<<j))){
						sub += (1<<j);
					}
				}
			}
			if(i)dp[mask][i] = min(dp[mask][i-1],dp[sub][i-1]+a[i]);
			else if(sub == 0){
				dp[mask][i] = min((ll)a[i],dp[mask][i]);
			}
		}
	}
	if(dp[(1<<n)-1][m-1] == inf){
		dp[(1<<n)-1][m-1] = -1;
	}
	cout<<dp[(1<<n)-1][m-1];
	return 0;
}