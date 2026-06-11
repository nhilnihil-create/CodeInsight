#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        int x;
        cin >> x;
        a[x] = i;
    }
    for (int i = 1; i < n + 1; i++)
    {
        if (i > 1)
            cout << " ";
        cout << a[i];
    }
    cout << endl;
    return 0;
}