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
    ll n , m ; cin >> n >> m;
    vector<vector<ll>> dp(m+1,vector<ll>(1<<n,INF));
    dp.at(0).at(0) = 0;
    for(int i=1;i<=m;i++){
        ll cost,keynum; cin >> cost >> keynum;
        ll keycomb = 0;
        rep(j,keynum){
            ll x; cin >> x;
            keycomb+=(1<<(x-1));
        }
        //cout << i << " " << keycomb << endl;
        rep(j,1<<n){
            bitset<12> jb(j),key(keycomb);
            ll z = (jb|key).to_ullong();
            //cout << j << " " << z << endl;
            dp.at(i).at(z) = min(dp.at(i).at(z),dp.at(i-1).at(j) + cost);
            dp.at(i).at(j) = min(dp.at(i).at(j),dp.at(i-1).at(j));            
        }
    }
    //pr2d(dp);
    if(dp.at(m).at((1<<n)-1) == INF){
        cout << -1 << endl;
    }else{
        cout << dp.at(m).at((1<<n)-1) << endl;
    }
    return 0;
}