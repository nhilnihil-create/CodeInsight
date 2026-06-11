#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main(){
    bool z = true;
    ll n;
    cin >> n;
    ll ans = 1;
    vector<ll> a(n + 1);
    vector<ll> vert(n + 1);//ある深さの頂点の個数
    vector<ll> leaves(n + 2, 0);//ある深さから深さnまでの葉の枚数
    rep(i, n + 1) cin >> a[i];
    rep(i, n + 1) leaves[i] = a[i];
    for (ll i = n; i >= 0;i--){
        leaves[i] += leaves[i + 1];
    }
    vert[0] = 1;
    rep (i,n){
        if(vert[i]<=a[i]){//条件を満たす二分木が存在するかどうか
            z = false;
            break;
        }
        vert[i+1] = min((vert[i] - a[i]) * 2, leaves[i+1]);//深さ i の頂点のうち葉ではないものの個数の2倍と深さi+1から深さnまでの葉の枚数のうちの小さい方
        ans += vert[i+1];
    }
    if(a[n]!=vert[n]) z = false;//n=0の時
    if (z) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}
