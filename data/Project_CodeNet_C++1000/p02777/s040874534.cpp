//                              ______  ______  ______
// .-----..-----..-----..-----.|    __||__    ||  __  |
// |     ||  _  ||     ||  _  ||  __  ||    __||  __  |
// |__|__||___  ||__|__||___  ||______||______||______|
//        |_____|       |_____|
//
# include <bits/stdc++.h>
using namespace std;
using msi = map<string, int>;

int main() {
    string s, t;
    cin >> s >> t;
    int a, b;
    cin >> a >> b;
    msi mp;
    mp[s] = a;
    mp[t] = b;
    string u;
    cin >> u;
    mp[u]--;

    printf("%d %d\n", mp[s], mp[t]);

    return 0;
}