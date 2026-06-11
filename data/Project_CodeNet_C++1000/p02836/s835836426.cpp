#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, M;
void func()
{
    string s, t;
    cin >> s;
    int ans(0);
    rep(i, 0, s.size() / 2)
    {
        if (s[i] != s[s.size() - i - 1])
            ++ans;
    }
    cout << ans << endl;
}
int main()
{
    func();
}