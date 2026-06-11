#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> ans(n + 1, 0);
    for (int i = n; i >= 1; i--)
    {
        int cnt = 0;
        for (int j = i; j <= n; j += i)
            cnt += ans[j];
        if (cnt % 2 != a[i])
            ans[i]++;
    }

    cout << accumulate(ans.begin(), ans.end(), 0) << endl;
    for (int i = 1; i <= n; i++)
        if (ans[i])
            cout << i << " ";
    cout << endl;

    return 0;
}