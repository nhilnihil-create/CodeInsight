#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using V = vector<int>;

int main(int argc, char const *argv[])
{
    int n, m, k; cin >> n >> m >> k;
    long long int a, b, c[200010], d[200010];
    c[0] = 0;
    rep(i,n) {
        cin >> a;
        c[i+1] = c[i] + a;
    }
    d[0] = 0;
    rep(i,m) {
        cin >> b;
        d[i+1] = d[i] + b;
    }
    int ans = 0;
    int j = m;
    rep(i,n+1) {
        if (k < c[i]) break;
        while (k < c[i] + d[j]) {
            j--;
        }
        ans = max(ans, i+j);
        //cout << ans << " " << i << " " << j << endl;
    }    
    cout << ans << endl;


    return 0;
}
