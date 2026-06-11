#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int k = 0;
    rep(i,n)
        if (a[i] != i + 1) k++;
    cout << (k <= 2 ? "YES" : "NO") << endl;
    return 0;
}
