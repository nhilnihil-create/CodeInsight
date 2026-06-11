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
int n,k;
vi a,f;
bool check(ll mid){
	// multiset<int> m;
	// rep(i,n){
	// 	m.insert(a[i]);
	// }
	int c = 0;
	rep(i,n){
		if(f[i]*a[i] > mid){
			ll temp = mid/f[i];
			c += abs(temp-a[i]);
		}
	}
	// rep(i,n){
	// 	// i?uto it = m.upper_bound(mid/temp);
	// 	if(it == m.begin()){
	// 		if(*it > mid/temp){
	// 			// cout<<i<<"\n";
	// 			c += (*it - mid/temp);
	// 			m.erase(it);
	// 		}
	// 		else{
	// 			m.erase(it);
	// 		}
	// 	}
	// 	else{
	// 		it--;
	// 		m.erase(it);	
	// 	}
	// }
	if(c <= k){
		return true;
	}
	return false;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	rep(i,n){
		int x;
		cin>>x;
		a.pb(x);
	}
	sort(all(a));
	ll l = 0;
	rep(i,n){
		int x;
		cin>>x;
		f.pb(x);
		// l = max(l,f[i]);
	}
	sort(all(f),greater<int>());
	ll r = 1e12 + 2;
	ll ans = r;
	// cout<<check(1)<<"\n";
	while(l <= r){
		ll mid = (l+r)/2;
		if(check(mid)){
			ans = mid;
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	cout<<ans;
	return 0;
}