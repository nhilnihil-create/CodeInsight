#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mod = 1000000007;
const ll INF = 1001001001;
const ll LINF = 1001001001001001001;

void prvec(vector<ll> vec){ //for debug
    ll n = vec.size();
    cout << "------------------------------------\n" ;
    rep(i,n) cout << i << " " << vec.at(i) << "\n";
    cout << "------------------------------------\n" ;
}

void pr2d(vector<vector<ll>> vec){ // for debug
    ll h = vec.size();
    ll w = vec.at(0).size();
    cout << "------------------------------------\n" ;
    rep(i,h){
        rep(j,w){
            cout << vec.at(i).at(j) << " ";
        }
        cout << "\n";
    }
    cout << "------------------------------------\n" ;
}

int main(){
    ll n , d, a; cin >> n >> d >> a;
    vector<pair<ll,ll>> xh(n);
    rep(i,n){
        cin >> xh.at(i).first >> xh.at(i).second;
    }
    sort(xh.begin(),xh.end());
    ll ans = 0;

    vector<ll> lst_place(0),lst_damage(0);
    lst_place.push_back(0);
    lst_damage.push_back(0);

    rep(i,n){
        //あらかじめHPから引いておく数を計算する
        auto it1 = lower_bound(lst_place.begin(),lst_place.end(),xh.at(i).first);
        auto it2 = lower_bound(lst_place.begin(),lst_place.end(),xh.at(i).first + 2*d);
        ll x = it1 - lst_place.begin() -1;
        ll y = it2 - lst_place.begin() -1;
        ll damage = lst_damage.at(y) - lst_damage.at(x);
        xh.at(i).second -= damage * a;


        //補正したHPのモンスターを倒すのに必要な爆弾の個数を求める
        ll bomb = 0;
        if(xh.at(i).second>=0){
            if(xh.at(i).second%a==0){
                bomb = xh.at(i).second/a;
            }else{
                bomb = (xh.at(i).second/a)+1;
            }
        }
        ans += bomb;
        

        //爆弾の数をlstに反映させる
        lst_place.push_back(xh.at(i).first + (2*d));
        lst_damage.push_back(lst_damage.at(i) + bomb);
    }
    cout << ans << endl;
    return 0;
}
