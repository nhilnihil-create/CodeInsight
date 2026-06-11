#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using ll = long long;

int main(){
    int p, q, r;
    cin >> p >> q >> r;
    int ans;
    ans = min(p+q,min(q+r,r+p));
    cout << ans << endl;
}