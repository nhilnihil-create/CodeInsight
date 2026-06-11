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
    int N,M;
    cin >> N >> M;

    vector<int> H(N);
    REP (i,N) {
        cin >> H[i];
    }

    vector<bool> T(N,true);
    int A,B;
    REP (i,M) {
        cin >> A >> B;
        if (H[A-1] > H[B-1]) {
            T[B-1] = false;
        }
        else if (H[A-1] < H[B-1]) {
            T[A-1] = false;
        }
        else {
            T[A-1] = false;
            T[B-1] = false;
        }
    }

    ll ans = 0;
    REP (i,N) {
        if (T[i]) {
            ans++;
        }
    }
 
    cout << ans << endl;

    return 0;
}
