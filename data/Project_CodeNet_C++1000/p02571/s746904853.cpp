#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    string s, t;
    cin >> s >> t;
    int ans = t.length();
    rep(i, s.length()-t.length()+1) {
        string ss = s.substr(i, t.length());
        int tmp = 0;
        rep(j, ss.length()) {
            if (t[j]!=ss[j]) tmp++;
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}