#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
int main(void){
    int n, m;
    cin >> n >> m;
    rep(i, m){
        int a;
        cin >> a;
        n -= a;
    }
    int ans = max(-1, n);
    cout << ans << endl;
    return 0;
}