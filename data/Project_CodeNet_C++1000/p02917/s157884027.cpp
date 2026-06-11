#include <bits/stdc++.h>
#include <string>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
 
int main()
{
    int n,ans;
 
    cin >> n; 
    vector<int> b(n-1);
    rep(i, n-1) {
        cin >> b[i];
    }
 
    ans = b[0];
    for (int i = 1;i < n - 1;++i) {
        ans += min(b[i-1], b[i]);
    }
    ans += b[n-2];
    cout << ans << endl;
 
    return 0;
}