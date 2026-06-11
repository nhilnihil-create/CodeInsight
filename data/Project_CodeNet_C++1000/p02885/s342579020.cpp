#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int ans = 0;
    ans = a-b*2;
    ans = max(ans, 0);

    cout << ans << endl;
    return 0;
}