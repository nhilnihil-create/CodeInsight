#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    map<char, int> mp;
    rep(i,s.size()) {
        mp[s[i]]++;
    }
    if (mp.size() == 2 && mp.begin()->second == 2 && next(mp.begin())->second == 2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
