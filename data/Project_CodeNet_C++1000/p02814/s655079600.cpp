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
const ll INF=1e9;
const double PI=acos(-1);
const int MAX=200010;

ll gcd(ll a,ll b) {
    if (a<b) swap(a,b);
    while (b>0) {
        ll tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}

ll lcm(ll a,ll b) {
    ll c=gcd(a,b);
    ll d=a*b/c;
    return d;
}

int main() {
    ios_base::sync_with_stdio(false); 

    ll n,m;
    cin >> n >> m;
    ll ans=0;
    vector<ll> b(n),c(n);
    rep(i,n) {
        ll a;
        cin >> a;
        while (a%2==0) {
            a/=2;
            ++c[i];
        }
        b[i]=a;
    }
    bool flag=0;
    rep(i,n-1) {
        if (c[i]!=c[i+1]) flag=1;
    }
    if (flag==1) cout << 0 << endl;
    else {
        ll l=1;
        ll p=1;
        rep(i,c[0]-1) p*=2;
        rep(i,n) {
            l=lcm(b[i],l);
            if (l*p>m) {
                cout << 0 << endl;
                return 0;
            }
        } 
        ll d=p*l;
        ll ans=m/(2*d);
        if (m%(2*d)>=d) ++ans;
        cout << ans << endl;
    }

    return 0;
}
