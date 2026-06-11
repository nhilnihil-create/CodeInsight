#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    string s;
    bool ans = false;
    cin >> s;
    map<char, int>mp;
    for (auto ss : s)mp[ss]++;
    auto p = mp.begin();
    if (mp.size() == 2 && (*p).second == 2 && (*(++p)).second == 2)ans = true;

    if (ans) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}