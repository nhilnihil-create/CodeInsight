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
typedef pair<int, int> P;

int main() {
    int N;
    cin >> N;

    int A[N];
    bool flag = false;
    REP(i, N){
        cin >> A[i];
        if(A[i] == 1) flag = true;
    }

    if(flag) {
        int x = 1, ans = 0;
        REP(i, N){
            if(A[i] == x) x++;
            else ans++;
        }
        cout << ans << endl;
    }
    else cout << -1 << endl;
}