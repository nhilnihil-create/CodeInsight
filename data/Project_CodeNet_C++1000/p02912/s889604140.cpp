#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<int> a;
    rep (i, n)
    {
        int temp;
        cin >> temp;
        a.push(temp);
    }

    rep (i, m)
    {
        int dc = a.top();
        a.pop();
        a.push(dc /= 2);
    }

    ll ans = 0;
    while (!a.empty())
    {
        int temp = a.top();
        a.pop();
        ans += temp;
    }
    cout << ans << endl;
    return 0;
}