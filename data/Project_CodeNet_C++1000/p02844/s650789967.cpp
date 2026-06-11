#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    rep(x, 1000) {
        vector<int> v;
        int nx = x;
        v.push_back(nx % 10);
        nx /= 10;
        while (nx) {
            v.push_back(nx % 10);
            nx /= 10;
        }
        while (v.size() != 3) v.push_back(0);
        reverse(v.begin(), v.end());
        int j = 0;
        rep(i, n) {
            if (s[i] - '0' == v[j]) j++;
            if (j == 3) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}