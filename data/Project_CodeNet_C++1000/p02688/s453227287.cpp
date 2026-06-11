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

    vector<int> A(110,0);
    REP (i, K) {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++) {
            int a;
            cin >> a;
            A[a-1]++;
        }
    }

    int ans = 0;
    REP (i,N) {
        if (A[i] > 0 ) {
            ans++;
        }
    }

    cout << N-ans << endl;

    return 0;
}
