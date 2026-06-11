// Author : Sarthak Kapoor
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int ll
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
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vi v(n);
	ll sum = 0;
	vi p(n+1,0);
	rep(i,n){
		cin>>v[i];
		p[v[i]]++;
	}
	vi cnt(n+1,0);
	rep(i,n+1){
		cnt[p[i]]++;
	}
	cnt[0] = 0;
	vi pre(n+1,0),pre1(n+1,0);
	repa(i,1,n+1){
		pre[i] = pre[i-1]+cnt[i];
		pre1[i] = pre1[i-1] + i*cnt[i];
	}
	vi f(n,0);
	repa(i,1,n+1){
		f[i-1] = pre1[i];
		f[i-1] += i*(pre[n] - pre[i]);
		f[i-1] /= i;
	}
	repa(i,1,n+1){
		int l = 0;
		int r = n-1;
		int ans = 0;
		while(l <= r){
			int mid = (l+r)/2;
			if(f[mid] >= i){
				ans = mid+1;
				l = mid+1;
			}
			else{
				r = mid-1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}