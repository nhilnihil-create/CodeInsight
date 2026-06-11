#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
        ll a,b,c,k;
        cin >> a >> b >> c >> k;
        ll ans = 0;
        ll t = k;
        k -= a;
        if(k<=0){
                ans += t;
                cout << ans << endl;
                return 0;
        }else{
                ans += a;
                k -= b;
                if(k<0){
                        cout << ans << endl;
                        return 0;
                }else{
                        ans -= k;
                        cout << ans << endl;
                        return 0;
                }
        }

}