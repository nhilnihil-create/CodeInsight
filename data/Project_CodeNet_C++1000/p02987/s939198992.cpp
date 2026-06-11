#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

string s;

int main() {
    bool ok = true;
    cin >> s;
    unordered_map<char,int> mp;
    for (auto c : s) {
        mp[c]++;
    }
    for (auto c : mp) {
        if (c.second != 2) {
            ok = false;
            break;
        }
    }
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
