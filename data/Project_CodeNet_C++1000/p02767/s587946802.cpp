#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int res = INT_MAX;
    for(int i = 0; i < 101; ++i)
    {
        int sum = 0;
        for(int j = 0; j < n; ++j)
        {
            sum += (a[j] - i) * (a[j] - i);
        }
        res = min(sum, res);
    }

    cout << res << "\n";
    return 0;
}