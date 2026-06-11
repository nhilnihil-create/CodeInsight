#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    ll A,B,N;
    cin >> A >> B >> N;

    if (B>N) {
        ll ans = (A*N)/B - A*(N/B);
        cout << ans << endl;
    }
    else {
        ll ans = (A*(B-1))/B-A*((B-1)/B);
        cout << ans << endl;
    }
}
