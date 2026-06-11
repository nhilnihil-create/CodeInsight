#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main()
{
    int n,ans;
    string s;
    char c[4];

    cin >> n >> s;

    ans = 0;
    for (int i = 0;i <= 999;++i) {
        c[0] =  i / 100;
        c[1] = (i - c[0] * 100)/10;
        c[2] = i - c[0] * 100 - c[1] * 10;
        int p = 0;
        for (int j = 0;j < n;++j) {
            if ((s.at(j)-'0') == c[p]) {
                ++p;
            }
            if (p == 3)
                break;
        }
        if (p == 3)
            ++ans;
    }

    cout << ans << endl;
}
