#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int inf = 1e9;
constexpr ll linf = 1e18;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        mp[a]++;
    }

    if (mp[0] == n) {
        cout << "Yes" << endl;
        return 0;
    }
    if (n % 3) {
        cout << "No" << endl;
        return 0;
    }

    vector<int> lst;
    for (auto &e: mp) {
        for (int i = 0; i < e.second / (n / 3); i++) lst.push_back(e.first);
    }
    if (lst.size() == 3 && (lst[0] ^ lst[1] ^ lst[2]) == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}