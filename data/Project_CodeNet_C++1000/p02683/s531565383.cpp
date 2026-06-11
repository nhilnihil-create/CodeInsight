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
    ll N,M,X;
    cin >> N >> M >> X;

    vector<vector<int>> A(N,vector<int>(M,0));
    vector<int> C(N);
    REP (i,N) {
        cin >> C[i];
        REP (j,M) {
            cin >> A[i][j];
        }
    }

    int ans = 10000000;
    int ptn = 1<<N;

    bool buyed = false;
    REP (mask,ptn) {
        vector<int> grasp(M);
        int charge = 0;
        REP (i,N) {
            if ((mask>>i)&1) {
                charge += C[i];
                REP (j,M) {
                    grasp[j] += A[i][j];
                }
            }
        }

        bool chk = true;
        REP (j,M) {
            if (grasp[j] < X) {
                chk = false;
            }
        }
        if (chk) {
            ans = min(ans,charge);
            buyed = true;
        }
    }

    if (buyed) {
        cout << ans << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}
