#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<int> b(n-1);
    rep(i,n-1) cin >> b[i];
    b.push_back(100100);
    int ans = 0;

    ans += b[0];
    rep(i,n-1){
        ans += min(b[i], b[i+1]);
    }

    cout << ans << endl;

    return 0;
}
