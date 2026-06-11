#include <bits/stdc++.h>
#include <string>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main()
{
    int l,r,ans;

    cin >> l >> r;

    ans = INT_MAX;
    for (int i=l;i<r;++i) {
        for (int j = i + 1;j <= r;++j) {
            ans=min(ans,(int)(((ll)i * j) % 2019));
            if (ans == 0)
                goto OWARI;
        }
    }
OWARI:
    cout << ans << endl;

    return 0;
}
