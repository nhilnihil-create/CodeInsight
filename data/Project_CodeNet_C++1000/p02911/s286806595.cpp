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
    int N, K, Q;
    cin >> N >> K >> Q;

    int A[Q];
    int P[N];
    REP(i, N){
        P[i] = K - Q;
    }

    REP(i, Q){
        cin >> A[i];
        P[A[i]-1]++;
    }

    int ans = 0;
    REP(i, N){
        if (P[i] > 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}