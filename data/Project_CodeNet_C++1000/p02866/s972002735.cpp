#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 998244353;
const int maxn = 1e6 + 5;

ll pw(ll x, ll y) {
    ll res=1;
    while (y) {
	if (y%2) res=res*x%mod;
	x=x*x%mod;y=y/2;
    }
    return ((res%mod)+mod)%mod;
}

int n;
ll cnt[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n;
    int hi = 0;
    for (int i=1; i<=n; i++) {
	int d;
	cin>>d;
	if (d==0) {
	    if (i!=1) out(0);
	}
	hi = max(hi, d);
	cnt[d]++;
    }

    if (cnt[0] != 1) out(0);

    ll ans = 1;
    for (int i=1; i<=hi; i++) {
	ll cur = pw(cnt[i-1], cnt[i]);
	ans=ans*cur%mod;
    }

    cout<<ans<<endl;    
    return 0;
}
