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
    string s;
    cin >> s;
    int r = 0;
    rep(i, s.size()) {
        if(s[i] == 'R') r++;
    }
    int ans = 0;
    rep(i, r) {
        if(s[i] == 'W') ans++;
    }
    ans = min(ans, r);
    ans = min(ans, n - r);
    cout << ans << endl;
    
    return 0;
}