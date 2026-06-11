#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define arep(x,n) for (int x: n)
using namespace std;

int main()
{
    int64_t h, w; cin >> h >> w;
    int64_t ans = 0,tmp;
    if(h == 1 || w == 1) ans = 1;
    else {
        if(h%2 == 0) {
            ans = w * h/2;
        } else {
            ans = w * (h-1)/2;
            if(w%2==0) {
                tmp = w/2;
            } else {
                tmp = w/2 + 1;
            }
            ans = ans + tmp;
        }
    }
    cout << ans << endl;
}