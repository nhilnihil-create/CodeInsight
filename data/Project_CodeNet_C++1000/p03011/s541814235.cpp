#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int mod = 1000000007;

int main(){
    int p,q,r;
    cin >> p >> q >> r;
    int ans = min(p+q,min(q+r,r+p));
    cout << ans << endl;
}