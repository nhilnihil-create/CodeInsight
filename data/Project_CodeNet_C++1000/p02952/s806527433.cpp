#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
int keta(int num)
{
    int cnt = 0;
    while (num)
    {
        num /= 10;
        cnt++;
    }
    return cnt;
}
int main()
{
    int s;
    cin >> s;
    // cout << keta(s) << endl;
    int ans = 0;
    rep(i, 1, s + 1)
    {
        if (keta(i) % 2 == 1)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
