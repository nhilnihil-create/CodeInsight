#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
/////////////////////////////////
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ma(n);
    rep(i, n)
    {
        cin >> a[i];
        ma[i] = a[i];
    }
    sort(ma.begin(), ma.end());
    int M = ma[n - 1];
    rep(i, n)
    {
        if (a[i] != M)
            cout << M << endl;
        else
            cout << ma[n - 2] << endl;
    }
}