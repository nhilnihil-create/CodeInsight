#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
#define dup(x,y) (((x)+(y)-1)/(y))
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
const int INTMAX = 2147483647;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n,d,a;cin >> n >> d >> a;
    vector<P> p(n);
    rep(i,n) cin >> p[i].first >> p[i].second;

    sort(p.begin(),p.end());
    ll tot = 0;
    queue<pair<ll,ll>> q;
    ll ans = 0;
    rep(i,n){
        ll x = p[i].first;
        ll h = p[i].second;
        while(q.size() && q.front().first < x){
            tot -= q.front().second;
            q.pop();
        }

        h -= tot;
        if(h>0){
            ll num = dup(h, a);
            ans += num;
            ll damage = num * a;
            tot += damage;
            q.emplace(x+2*d, damage);
        }
    }
    cout << ans << endl;
    return 0;
}