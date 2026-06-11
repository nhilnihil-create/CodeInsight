#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int num = 1;
    vector<int> b;
    rep(i, n)
    {
        cin >> a[i];
        if (a[i] == num)
        {
            b.push_back(a[i]);
            num++;
        }
    }
    int ans = n - b.size();
    if (b.size() > 0)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}