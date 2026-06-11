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

    int B[N-1];
    REP(i, N-1){
        cin >> B[i];
    }

    int A[N];
    A[0] = B[0];
    A[N-1] = B[N-2];
    FOR(i, 1, N-2){
        A[i] = min(B[i-1], B[i]);
    }

    int ans = 0;
    REP(i, N){
        ans += A[i];
    }

    cout << ans << endl;
}
