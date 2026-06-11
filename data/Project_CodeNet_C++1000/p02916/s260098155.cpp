#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; ++i) 
    {
        cin >> a[i];
        --a[i];
    }
    for(int i = 0; i < n; ++i) cin >> b[i];
    for(int i = 0; i < n - 1; ++i) cin >> c[i];

    int res = 0;
    for(int i = 0; i < n; ++i)
    {
        res += b[a[i]];
        if(i > 0 && a[i] == a[i - 1] + 1)
            res += c[a[i - 1]];
    }
    cout << res << "\n";
    return 0;
}
