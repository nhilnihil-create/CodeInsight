#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^18 -> 18回
// double pi = M_PI or acos(-1)

int main() {
    int n;
    cin >> n;
    vector<int> a(n - 1);
    rep(i, n - 1) {
        cin >> a.at(i);
        a.at(i)--; // 0-index
    }
    vector<int> s(n, 0);
    rep(i, n - 1) {
        s.at(a.at(i))++;
    }
    rep(i, n) {
        cout << s.at(i) << endl;
    }
    return 0;
}
