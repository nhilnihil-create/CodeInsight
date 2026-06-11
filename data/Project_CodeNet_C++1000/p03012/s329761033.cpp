#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, res = INT_MAX;
    cin >> n;


    vector<int> w(n), s(n + 1);
    for(int i = 0; i < n; ++i)
    {
        cin >> w[i];
        s[i + 1] = s[i] + w[i];
    }

    for(int i = 1; i <= n; ++i)
    {
        res = min(res, abs(s[n] - s[i] - s[i]));
    }

    cout << res << endl;

    return 0;
}