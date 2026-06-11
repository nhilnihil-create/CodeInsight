#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=998244353;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int n;
vl x(60),y(60);

int fnc(ll dx,ll dy){
    int res = 0;
    rep(i,n){
        ll nx = x[i] + dx;
        ll ny = y[i] + dy;
        rep(j,n){
            if(i==j) continue;
            if(x[j]==nx && y[j]==ny){
                res++;
                break;
            }
        }
    }
    return res;
}

int main(){
    cin >> n;
    rep(i,n) cin >> x[i] >> y[i];
    vector<pair<ll,ll>> cn;
    rep(i,n){
        for(int j=i+1;j<n;j++){
            ll dx = x[j] - x[i];
            ll dy = y[j] - y[i];
            cn.push_back({dx,dy});
            cn.push_back({-dx,-dy});
            //cout << dx << " " << dy << endl;
        }
    }
    ll ma = 0;
    rep(i,cn.size()){
        chmax(ma,fnc(cn[i].first,cn[i].second));
    }
    ll ans = 1 + ((n-1) - ma);
    cout << ans << endl;
}