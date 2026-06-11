#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int main() {
    int N, D;
    cin >> N >> D;

    vector<vector<int>> X(N, vector<int>(D));
    REP(i, N){
        REP(j, D){
            cin >> X[i][j];
        }
    }

    double Dist;
    int ans = 0;
    REP(i, N-1){
        FOR(j, i+1, N-1){
            double D1 = 0;
            REP(k, D){
                D1 += pow((double)X[i][k] - X[j][k], 2);
            }
            Dist = sqrt(D1);
            if (floor(Dist) == Dist) ans++;
        }
    }

    cout << ans << endl;
}