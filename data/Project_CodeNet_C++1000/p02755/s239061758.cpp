#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main()
{
    int a,b,ans,flg;

    cin >> a >> b;

    ans = -1;
    flg = 0;
    for (int x = 1;x < 10000;++x) {
        if ((x * 8 / 100 == a) && (x * 10 / 100 == b)) {
            ans = x;
            ++flg;
            break;
        }
    }

    std::cout << ans << endl;
}
