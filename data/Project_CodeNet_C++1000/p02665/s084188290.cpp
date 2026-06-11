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
    ll n ; cin >> n;
    vector<ll> a(n+1);
    rep(i,n+1) cin >> a.at(i);
    
    if(n!=0 && a.at(0) != 0){
        cout << -1 << endl;
        return 0;
    }
    if(n==0){
        if(a.at(0) == 1){
            cout << 1 << endl;
        }else{
            cout << -1 << endl;
        }
        return 0;
    }

    vector<ll> rui(n+1,0); //rui 制限の値
    rui.at(n) = a.at(n);
    for(int i=n-1;i>=0;i--){
        rui.at(i) = rui.at(i+1) + a.at(i);
    }

    vector<ll> nokori(n+1,0);
    nokori.at(0) = 1;

    for(int i=1;i<n;i++){
        //cout << i << endl;
        ll max_bunki = nokori.at(i-1)*2;
        if(max_bunki <= rui.at(i)){
            nokori.at(i) = nokori.at(i-1) * 2 - a.at(i);
        }else{
            nokori.at(i) = rui.at(i) - a.at(i);
        }
        if(nokori.at(i) <= 0){
            cout << -1 << endl;
            return 0;
        }
    }

    if(a.at(n) < nokori.at(n-1) || a.at(n) > nokori.at(n-1)*2){
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;
    rep(i,n+1) ans+=a.at(i);
    rep(i,n) ans+=nokori.at(i);
    cout << ans << endl;
    return 0;
}
