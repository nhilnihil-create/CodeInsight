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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int ans = INF;
    rep(i, n - m + 1) {
        int cnt = 0;
        rep(j, m) {
            if(s[i + j] != t[j]) cnt++;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}