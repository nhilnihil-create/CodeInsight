#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //10^19 < 9223372036854775807
typedef unsigned long long ull; //10^20 < 18446744073709551615

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define FORA(i,I) for(const auto& i:I)
#define ALL(x) x.begin(),x.end() 
#define SIZE(x) ll(x.size()) 

#define MOD 1000000007

ll GCD(ll a, ll b) {
    if (a%b == 0) return b;
    return GCD(b, a%b);
}

int main(void)
{
    ll K;
    cin >> K;

    ll ans = 0;
    FOR (a,1,K) {
        FOR (b,1,K) {
            FOR (c,1,K) {
                ans += GCD(GCD(a,b),c);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
