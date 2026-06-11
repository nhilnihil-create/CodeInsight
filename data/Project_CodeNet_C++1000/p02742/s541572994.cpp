#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;

int main(){
    ll h, w;
    cin >> h >> w;
    ll ans;
    if(h == 1 || w == 1){
        cout << 1 << endl;
        return 0;
    }
    if(w % 2 == 0){
        ans = (w/2) * h;
    }else{
        if(h % 2 == 0){
            ans = (w/2+1)*h/2 + (w/2)*h/2;
        }else{
            ll from = (w/2+1)*(h/2+1);
            ll to = (w/2)*(h/2);
            ans = from + to;
        }
    }
    cout << ans << endl;
}