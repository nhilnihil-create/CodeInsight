#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;
using pr = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pr> t(n, {0,0});

    int p;
    string s;
    rep(i, m) {
        cin >> p >> s;
        p--;
        if (s == "AC") {
            t[p].first++;
        }
        else {
            if (t[p].first < 1) {
                t[p].second++;
            }
        }
    }

    int ac = 0;
    int wa = 0;
    rep(i, n) {
        if (t[i].first > 0) {
            ac++;
            wa += t[i].second;
        }
    }

    cout << ac << " " << wa << endl;
    return 0;
}