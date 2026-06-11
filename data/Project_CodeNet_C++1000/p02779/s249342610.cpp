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
    rep(i, n) cin >> a[i];
    set<int> s;
    rep(i, n)
    {
        if (s.count(a[i]))
        {
            cout << "NO" << endl;
            return 0;
        }
        s.insert(a[i]);
    }
    cout << "YES" << endl;
    return 0;
}