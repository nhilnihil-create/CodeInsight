#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    string s;
    cin >> s;
    int ans = 0;

    rep(i, s.length())
    {
        if (s[i] != s[s.length()-1-i])
        {
            ans++;
        }
    }

    cout << ans / 2 << endl;

    return 0;
}