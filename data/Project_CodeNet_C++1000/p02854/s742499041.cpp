#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int n;
    cin >> n;
    vector<ll> A(n + 1, 0);
    A[0] = 0;
    rrep(i, n) {
        ll a;
        cin >> a;
        A[i] = A[i - 1] + a; 
    }
    ll ans = LINF;
    rrep(i, n) {
        ll value = abs(2 * A[i] - A[n]);
        ans = min(ans, value);
    }
    cout << ans << endl;

    return 0;
}