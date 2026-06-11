#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll; //10^19 < 9223372036854775807
typedef unsigned long long ull; //10^20 < 18446744073709551615

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define FORA(i,I) for(const auto& i:I)
#define ALL(x) x.begin(),x.end() 
#define SIZE(x) ll(x.size()) 

#define MOD 1000000007
#define MAX 1000000000000000000

int main(void)
{
    ll N;
    cin >> N;
    ll ans = 1;

    vector<ll> A(N);
    REP (i, N) {
        cin >> A[i];
        if ( A[i] == 0 ) {
            cout << 0 << endl;
            return 0;
        }
    }

    REP (i, N) {
        if ( ans <= MAX / A[i]) {
            ans *= A[i];
        }
        else {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;
    
    return 0;
}
