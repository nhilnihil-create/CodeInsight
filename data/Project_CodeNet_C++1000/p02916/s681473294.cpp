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

/* --------------------------------------------------- */

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n - 1);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    rep(i, n) cin >> b[i];
    rep(i, n - 1) cin >> c[i];
    
    int ans = 0;
    rep(i, n) {
        ans += b[a[i]];
        if(i == n - 1) continue;
        if(a[i + 1] == a[i] + 1) ans += c[a[i]];
    }

    cout << ans << endl;

    return 0;
}