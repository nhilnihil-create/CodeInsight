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
    ll X,N,num;
    cin >> X >> N;

    if (N == 0) {
        cout << X << endl;
        return 0;
    }

    vector<bool> p(102,false);
    REP (i,N) {
        cin >> num;
        p[num] = true;
    }

    ll diff = 1000;
    REP (i,102) {
        if (p[i] == false) {
            diff = min (abs(X-i), diff);
        }
    }

    if (p[X-diff] == false) {
        cout << X-diff << endl;
    }
    else {
        cout << X+diff << endl;
    }


    return 0;
}
