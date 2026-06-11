#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

ll vert[100007];//ある深さの頂点の個数
ll leaves[100007];//ある深さから深さnまでの葉の枚数
int main(){
    bool z = true;
    ll n;
    cin >> n;
    ll ans = 1;
    vector<ll> a(n + 1);
    rep(i, n + 1) cin >> a[i];
    leaves[n + 1] = 0;
    for (ll i = n; i >= 0;i--){
        leaves[i] = leaves[i + 1] + a[i];
    }
    vert[0] =1;
    for (ll i = 1; i < n; i++){
        if(vert[i-1]<=a[i-1]){//条件を満たす二分木が存在するかどうか
            z = false;
            break;
        }
        if((vert[i-1]-a[i-1])*2<=a[i])z = false;
        vert[i] = min((vert[i - 1] - a[i - 1]) * 2, leaves[i]); //深さ d − 1 の頂点のうち葉ではないものの個数の2倍と深さiから深さnまでの葉の枚数のうちの小さい方
        ans += vert[i];
    }
    ans += a[n];
    if(n!=0&&(vert[n-1]-a[n-1])*2<a[n])z = false;
    if(n==0&&a[0]==1)ans = 1;
    if(n==0&&a[0]!=1)z = false;
    if (z)
    {
        cout << ans << endl;
    }
    else{
        cout << -1 << endl;
    }
}
