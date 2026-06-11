#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    int p,q,r;
    cin >> p >> q >> r;
    int ans = min(min(p+q,q+r),p+r);
    cout << ans << endl;
    return 0;
}