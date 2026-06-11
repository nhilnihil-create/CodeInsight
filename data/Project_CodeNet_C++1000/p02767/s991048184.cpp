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
ll mod = 1e+9 + 7;

int main(){
    int N, P1, P2, sum = 0;
    cin >> N;
    int X[N];

    REP(i, N){
        cin >> X[i];
        sum += X[i];
    }

    P1 = sum/N;
    P2 = ceil((double)sum/(double)N);

    ll ans1 = 0, ans2 = 0;
    REP(i, N){
        ans1 += pow((X[i]-P1), 2);
        ans2 += pow((X[i]-P2), 2);
    }

    ll ans = min(ans1, ans2);

    cout << ans << endl;

    return 0;
}
