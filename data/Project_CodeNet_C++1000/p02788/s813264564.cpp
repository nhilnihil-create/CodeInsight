#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const ll MOD=1e9+7;
const int INF=2e9;
const double PI=acos(-1);
const int MAX=200010;


int main() {
    ios_base::sync_with_stdio(false);

    ll n,d,a;
    cin >> n >> d >> a;
    vector<pair<ll,ll>> p(n);
    rep(i,n) cin >> p[i].first >> p[i].second;
    sort(p.begin(),p.end());
    queue<pair<ll,ll>> q;
    ll cnt=0,ans=0;
    rep(i,n) {
        while (!q.empty()) {
            pair<ll,ll> pp=q.front();
            if (p[i].first<=pp.first) break;
            else {
                cnt-=pp.second;
                q.pop();
            }
        }
        ll tans=(p[i].second+a-1)/a-cnt;
        if (tans>0) {
            ans+=tans;
            cnt+=tans;
            q.push({p[i].first+2*d,tans});
        }
    }
    cout << ans << endl;

    return 0;
}
