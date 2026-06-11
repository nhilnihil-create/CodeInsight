#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int cnt = 0;
    string r;
    cin >> r;
    string s = r;
    reverse(r.begin(), r.end());
    // cout << r << "," << s << endl;
    rep(i, s.size()) {
        if(s[i] != r[i]) {
            cnt++;
        }
    }

    cout << cnt / 2 << endl;
    return 0;
}
