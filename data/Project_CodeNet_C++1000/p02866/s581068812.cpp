#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=998244353;
const ll INF=2e15;
const double PI=acos(-1);

vector<pair<ll,ll>> vectorCnt(vector<ll> a) {
    sort(a.begin(),a.end());
    int n=a.size();
    vector<pair<ll,ll>> b;
    ll cnt=1;
    rep(i,n-1) {
            if (a[i+1]!=a[i]) {
                b.push_back(make_pair(a[i],cnt));
                cnt=1;
            } else {
                ++cnt;
            }
    }
    b.push_back(make_pair(a[n-1],cnt));
    return b;
}

ll binary_power(ll a, ll n) {
    if (n==0) return 1;
    ll k=binary_power(a,n/2);
    if (n%2==0) return (k*k)%MOD;
    else return (((k*k)%MOD)*a)%MOD;
}


int main() {
    ios_base::sync_with_stdio(false); 

    int n;
    cin >> n;
    vector<ll> d(n);
    bool invalid=0;
    rep(i,n) {
        cin >> d[i];
        if (i==0 && d[i]!=0) invalid=1;
        if (i>0 && d[i]==0) invalid=1;
    }
    sort(d.begin(),d.end());
    vector<pair<ll,ll>> p=vectorCnt(d);
    int m=p.size();
    ll ans=1;
    repr(i,1,m-1) {
        ans=(ans*binary_power(p[i].second,p[i+1].second))%MOD;
        if (p[i].first+1!=p[i+1].first) invalid=1;
    }
    if (!invalid) cout << ans << endl;
    else cout << 0 << endl;

    return 0;
}
