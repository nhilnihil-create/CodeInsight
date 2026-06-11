#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 1000000000;
const double PI = acos(-1);
const int mod = 1000000007;


int main()
{
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    rep(i, 1000) {
        int first = i / 100;
        int second = (i%100) / 10;
        int third = i % 10;
        // 1桁目
        bool is_ok = false;
        int now = -1;
        rep(j, n) {
            if (first == s[j] - '0') {
                is_ok = true;
                now = j;
                break;
            }
        }
        if (!is_ok) continue;
        // 2桁目
        is_ok = false;
        for (int j = now + 1; j < n; j++) {
            if (second == s[j] - '0') {
                is_ok = true;
                now = j;
                break;
            }
        }
        if (!is_ok) continue;
        // 3桁目
        is_ok = false;
        for (int j = now + 1; j < n; j++) {
            if (third == s[j] - '0') {
                is_ok = true;
                now = j;
                break;
            }
        }
        if (!is_ok) continue;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
