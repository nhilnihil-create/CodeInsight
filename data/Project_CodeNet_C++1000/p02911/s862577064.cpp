#include <bits/stdc++.h>
#include <string>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main()
{
    int n,k,q;

    cin >> n >> k >> q; 
    vector<int> p(n);
    rep(i, q) {
        int m;
        cin >> m;
        ++p[m-1];
    }

    rep(i, n) {
        string ans = "No";
        if (k+p[i]-q > 0)
            ans = "Yes";
        cout << ans << endl;
    }

    return 0;
}