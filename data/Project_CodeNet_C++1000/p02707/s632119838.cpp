#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
////////////////////////////////////////////////
int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    rep(i, n - 1)
    {
        int k;
        cin >> k;
        a[k] += 1;
    }
    for (int i = 1; i < n + 1; i++)
        cout << a[i] << endl;
}
