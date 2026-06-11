#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

ll mod=1000000007;
int main() {
	ll x,y;
	cin >> x >> y;
	if((x+y)%3!=0){
		cout << 0 << endl;
		return 0;
	}
	ll a,b;
	a=(2*x-y)/3;
	b=(2*y-x)/3;
	if(a<0||b<0){
		cout << 0 << endl;
		return 0;
	}
	ll res=1;
	for(ll i=a+b;i>=b+1;i--){
		res=res*i%mod;
	}
	for(ll i=a;i>=1;i--){
		res=res*modinv(i,mod)%mod;
	}
	cout << res%mod << endl;
}
