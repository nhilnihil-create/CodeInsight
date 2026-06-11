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

    int x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a),q(b),r(c+x+y);
    rep(i,a) cin >> p[i];
    rep(i,b) cin >> q[i];
    sort(p.begin(),p.end(),greater<>());
    sort(q.begin(),q.end(),greater<>());
    rep(i,c) cin >> r[i];
    int xx=min(x,a),yy=min(y,b);
    rep(i,xx) r[i+c]=p[i];
    rep(i,yy) r[i+c+x]=q[i];
    sort(r.begin(),r.end(),greater<>());
    ll ans=0;
    rep(i,x+y) ans+=r[i];
    cout << ans << endl;
    
    return 0;
}
