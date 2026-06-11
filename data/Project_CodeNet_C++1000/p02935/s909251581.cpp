#include <bits/stdc++.h>
#include <string>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main()
{
    int n;
    double ans;

    cin >> n; 
    vector<int> v(n);
    rep(i, n) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    ans = v[0];
    rep(i,n-1) {
        ans = (double)(ans + v[i + 1]) / 2.0;
    }

    cout << ans << endl;

    return 0;
}
