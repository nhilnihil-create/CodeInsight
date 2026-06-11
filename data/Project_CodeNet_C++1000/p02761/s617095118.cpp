#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main()
{
    int n,m,ans,flg;

    cin >> n >> m;
    vector<int> s(m);
    vector<char> c(m);
    rep(i, m) {
        cin >> s[i] >> c[i];
    }

    for (ans = 0;ans <= 999;++ans) {
        string sans = to_string(ans);
        flg = 0;
        if ((int)sans.size()==n) {
            rep(i, m) {
                if (s[i] <= (int)sans.size()) {
                    if (sans[s[i] - 1] != c[i]) {
                        ++flg;
                        break;
                    }
                }
            }
            if (flg == 0)
                break;
        }
    }
    if (ans>999 || flg != 0)
        ans = -1;

    std::cout << ans << endl;
}
