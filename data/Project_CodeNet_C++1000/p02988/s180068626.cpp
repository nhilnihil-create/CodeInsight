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
    int N;
    cin >> N;

    int p[N];
    REP(i, N){
        cin >> p[i];
    }

    int ans = 0;
    FOR(i, 1, N-2){
        int X[3] = {p[i-1], p[i], p[i+1]};
        sort(X, X+3);

        if(p[i] == X[1]) ans++;
    }
    cout << ans << endl;
}