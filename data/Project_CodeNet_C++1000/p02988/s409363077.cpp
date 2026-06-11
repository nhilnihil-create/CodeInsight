#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p.at(i);

    int count = 0;
    rep(i, n - 2) {
        if (p.at(i) < p.at(i + 1) && p.at(i + 1) < p.at(i + 2) ||
            p.at(i + 2) < p.at(i + 1) && p.at(i + 1) < p.at(i)) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
