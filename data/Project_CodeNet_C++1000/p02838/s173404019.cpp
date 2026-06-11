#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long ll;
using namespace std;

const int mod = 1e9 +7;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    ll res = 0;
    rep(d, 60){//d桁目を見る
        ll n0 = 0, n1 = 0;//d桁目の0の個数、１の個数
        rep(i,n){
            if((a[i]>>d)&1){
                n1++;
            }
            else{
                n0++;
            }
        }
        //直ぐにllを超えうるので適宜modで割っている。
        ll tmp = (1ll << d) % mod;//2^dを作る。llは64bitということ
        ll n = n0 * n1 % mod;
        tmp = tmp * n %mod;
        res = (res + tmp) % mod;
    }
    cout << res << endl;
}