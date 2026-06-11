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

int main(void)
{
    ll N,K;
    cin >> N >> K;

    vector<int> H(N);
    REP (i,N) {
        cin >> H[i];
    }

    ll ans = 0;
    sort(H.begin(),H.end());
    REP (i,N-K) {
        ans += H[i];
    }

    cout << ans << endl;

    return 0;
}
