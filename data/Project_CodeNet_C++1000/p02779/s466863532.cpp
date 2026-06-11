#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    if (unique(a.begin(), a.end()) == a.end()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
