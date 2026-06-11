#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, res = 0;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = 0; i < n - 1; ++i)
        for(int j = i + 1; j < n; ++j)
            res += a[i] * a[j];

    cout << res << "\n";
    return 0;
}
