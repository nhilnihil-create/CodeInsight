#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    unsigned k;
    cin >> k;
    queue<ll> que;
    rep(i, 9) que.push(i + 1);
    vector<ll> ans;
    while (1)
    {
        ll a = que.front();
        que.pop();
        ans.emplace_back(a);
        if (ans.size() == k)
        {
            cout << a << endl;
            return 0;
        }
        ll f = a % 10;
        a *= 10;
        if (f != 0)
            que.push(a + f - 1);
        que.push(a + f);
        if (f != 9)
            que.push(a + f + 1);
    }
}