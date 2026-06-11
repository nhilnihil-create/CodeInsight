#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define REP(i,n) for (int i=1;i<=(n);i++)
typedef long long ll;

int main() {
    ll h,w;
    cin >> h >> w;
    ll kisuu = (h+1)/2;
    ll guusuu = h/2;
    ll ans = 0;
    REP(i,w){
        if(i%2==1) ans+=kisuu;
        else ans += guusuu;
    }
    if(h==1||w==1) cout << "1" << endl;
    else cout << ans << endl;
}