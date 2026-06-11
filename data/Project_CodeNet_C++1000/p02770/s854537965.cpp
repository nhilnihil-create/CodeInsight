#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
ll const mod = 1e9+7;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

template<typename T1,typename T2>ostream& operator<<(ostream& os,const pair<T1,T2>& a) {os << "(" << a.first << "," << a.second << ")";return os;}

int main() {
    int k,q;
    cin >> k >> q;
    array<ll,5000> d;
    for (int i = 0;i < k;++i) cin >> d[i];
    while (q--) {
        ll n,x,m;
        cin >> n >> x >> m;
        n--;
        x %= m;
        ll sum = 0,z = 0,ans = n;
        for (int i = 0;i < k;++i) sum += d[i]%m;
        for (int i = 0;i < k;++i) if (d[i]%m == 0) z++;
        ll a = (n/(m*k))*sum%mod,b = (n/(m*k))*m%mod*z%mod;
        n %= m*k;
        (a += (x+(n/k)*sum)/m) %= mod;
        (b += (n/k)*z) %= mod;
        (ans -= a+b) %= mod;
        (ans += mod*2) %= mod;
        (x += sum*(n/k)) %= m;
        n %= k;
        for (int i = 0;i < n;++i) {
            if (x >= (x+d[i])%m) ans--;
            x = (x+d[i])%m;
        }
        cout << (ans+mod)%mod << "\n";
    }
}