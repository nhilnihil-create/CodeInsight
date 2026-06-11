//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

int main () {
    int x; cin >> x;
    for (int i = 0; i <= 7; i++) {
        if (400 + 200 * i <= x && x < 600 + 200*i) cout << 8-i << endl;
    }

    return 0;
}