#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;

ll pw(ll x, ll y) {
    ll res=1;
    while (y) {
	if (y%2) res=res*x%mod;
	x=x*x%mod;y=y/2;
    }
    return ((res%mod)+mod)%mod;
}

ll nc2(ll n) {
    if (n<2) return 0;
    ll res = n*(n-1)%mod;
    res *= pw(2, mod-2);
    res %= mod;
    return res;
}

int n, k;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    
    cin>>n>>k;
    for (int i=0; i<n; i++) {
	cin>>a[i];
    }
    ll inv0=0;
    for (int i=0; i<n; i++) {
	for (int j=i+1; j<n; j++) {
	    if (a[i]>a[j]) {
		inv0++;
	    }
	}
    }


    ll inv1=0;
    for (int i=0; i<n; i++) {
	for (int j=0; j<n; j++) {
	    if (a[i]>a[j]) {
		inv1++;
	    }
	}
    }

    ll res = 1ll*k*inv0%mod;
    ll res2 = nc2(k)*inv1%mod;
    res += res2;
    res %= mod;
    cout<<res<<endl;
    
    
    return 0;
}
