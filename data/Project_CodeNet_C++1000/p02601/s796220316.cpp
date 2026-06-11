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
    int a, b, c; cin >> a >> b >> c;//c > b > aにする
    int k; cin >> k;
    int cnt = 0;
     while (b <= a) {
        b *= 2;
        cnt++;
    }
    while (c <= b) {
        c *= 2;
        cnt++;
    }
    
    if (cnt <= k) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}