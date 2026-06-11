#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

int main() {
    string s;
    cin >> s;
    s.push_back('R');
    int n = s.size();
    vector<string> sections;
    string t;
    rep(i,n) {
        if (t.back() == 'L' && s[i] == 'R') {
            sections.push_back(t);
            t = "";
        }
        t.push_back(s[i]);
    }
    vector<int> ans;
    for (string sec : sections) {
        int sz = sec.size();
        int minians[sz];
        rep(i,sz) minians[i] = 0;
        int border;
        rep(i,sz-1) {
            if (sec[i] == 'R'&& sec[i+1] == 'L') border = i;
        }
        rep(i,sz) {
            if (abs(border-i)%2 == 0) {
                minians[border]++;
            }
            else {
                minians[border+1]++;
            }
        }
        rep(i,sz) {
            ans.push_back(minians[i]);
        }
    }
    rep(i,n-1) {
        cout << ans[i];
        if (i <= n-2) cout << " ";
    }
    cout << endl;
}