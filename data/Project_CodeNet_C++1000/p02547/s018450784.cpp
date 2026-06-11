#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n; cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        cin >> b[i];
    }
    for (int i = 0; i < n - 2; ++i)
    {
        if (a[i] == b[i] && a[i + 1] == b[i + 1] && a[i + 2] == b[i + 2]) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
