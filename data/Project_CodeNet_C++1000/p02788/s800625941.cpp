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
    ll n,d,a;cin >> n >> d >> a;
    vector<pair<ll,ll>> p(n);
    rep(i,n) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());
    vi vec(n);
    rep(i,n) vec[i] = p[i].first;
    vl attacknum(n+10,0);

    ll ans = 0;
    rep(i,n){
        attacknum[i] += attacknum[max(i-1, 0)];
        ll x = p[i].first;
        ll hp = p[i].second;
        hp -= max(attacknum[i] * a, 0LL);

        ll num = dup(hp, a);
        if(num < 0) num = 0;
        attacknum[i] += num;
        ans += num;

        int id = upper_bound(vec.begin(), vec.end(), x + 2 * d) - vec.begin();
        attacknum[min(id, (int)n)] -= num;
    }
    cout << ans << endl;
}