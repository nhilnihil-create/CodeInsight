#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n,ans;
    char s[10];

    cin >> n;

    ans = 0;
    rep(i,n) {
        sprintf(s, "%d", i + 1);
        if (strlen(s) % 2 == 1)
            ++ans;
    }

    cout << ans << endl;
}
