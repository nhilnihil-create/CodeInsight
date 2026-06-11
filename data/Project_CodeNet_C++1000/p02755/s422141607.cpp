#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define arep(x,n) for (int x: n)
using namespace std;

int main()
{
    int a,b; cin >> a >> b;
    bool z = false;
    int ans;
    for(int i = 13; i <= 1000; i++) {
        int tmpa,tmpb;
        tmpa = 0.08 * i;
        tmpb = 0.1 * i;
        if(tmpa == a && tmpb == b) {
            z = true;
            ans = i;
            break;
        }
    }
    if(z) cout << ans << endl;
    else cout << -1 << endl;
}