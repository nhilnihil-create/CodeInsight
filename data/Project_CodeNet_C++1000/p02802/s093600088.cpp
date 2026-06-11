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

struct result {
    string state;
    int pena;
};

int main(void)
{
    ll N,M;
    cin >> N >> M;

    vector<pair<int,string>> ps(M+1);
    vector<result> A(N);
    A.push_back({"",0});

    int ok = 0;
    int ng = 0;

    REP (i,M) {
        cin >> ps[i].first >> ps[i].second;
    }

    REP (i,M) {
        if ( A[ps[i].first].state != "AC" ) {
            A[ps[i].first].state = ps[i].second;
        
            if ( A[ps[i].first].state == "WA" ) {
                A[ps[i].first].pena++;
            }
            else if ( A[ps[i].first].state == "AC" ) {
                ok++;
                ng += A[ps[i].first].pena;
            }
        }
    }

    cout << ok << " " << ng << endl;

    return 0;
}
