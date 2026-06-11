#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60; //intじゃ扱えないことに注意！
using P = pair<int,int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++) //範囲外参照とループの初期化に注意！

const ll MX = 1e18;
int main() {
    int n;
    cin >> n;
    ll ans = 1;
    bool ng = false;
    rep(i,n){
        ll a;
        cin >> a;
        if(a == 0){
            cout << 0 << endl;
            return 0;
        }
        if(ng || MX/ans < a){ //本当はMX < a*ansとやりたい
            ng = true;
        }
        ans *= a;
    }
    if(ng) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}