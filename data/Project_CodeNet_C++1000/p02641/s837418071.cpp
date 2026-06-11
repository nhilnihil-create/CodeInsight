#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int x, n;
    cin >> x >> n;
    if (n == 0)
    {
        cout << x << endl;
        return 0;
    }
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    sort(p.begin(), p.end());
    queue<int>
        not_p;
    int j = 0;
    for (int i = 0; i <= 110; i++)
    {
        if (i == p[j])
        {
            j++;
        }
        else
        {
            not_p.push(i);
        }
    }
    // while (!not_p.empty())
    // {
    //     cout << not_p.front() << endl;
    //     not_p.pop();
    // }

    int ans = 10000000;
    int res = 10000000;
    while (!not_p.empty())
    {
        int tmp = abs(not_p.front() - x);
        // cout << tmp << ' ' << not_p.front() << endl;
        if (res > tmp)
        {
            res = tmp;           //absを保持する変数。小さければ小さいほどよい
            ans = not_p.front(); //表示する結果を保持
        }
        not_p.pop();
    }
    cout << ans << endl;
}
