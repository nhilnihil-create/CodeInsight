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
    int N, X;
    cin >> N >> X;

    int L[N];
    REP(i, N){
        cin >> L[i];
    }

    int ans = 1, D = 0;
    FOR(i, 1, N){
        D = D + L[i-1];

        if (D <= X) ans++;
        else break;
    }

    cout << ans << endl;
}