#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,x,n) for (int i = x; i < n; i++)
using ll = long long int;
int main() {
    ll N;
    cin >> N;
    ll ans=0;
    rep2(i,1,N+1) {
        ll X = N/i;
        ans += X*(X+1)*i/2;
    }
    cout << ans << endl;
    return 0;
}