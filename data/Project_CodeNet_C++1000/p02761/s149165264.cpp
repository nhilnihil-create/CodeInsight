#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll n, m;
    cin >> n >> m;
    vector<P> p(m);
    rep(i,m) cin >> p[i].first >> p[i].second;
    rep(i,1000){
        ll keta=1, nx=i/10;
        vector<ll> d(1,i%10);
        while(nx){
            keta++;
            d.push_back(nx%10);
            nx/=10;
        }
        if(keta != n) continue;
        bool ok=true;
        reverse(all(d));
        rep(i,m){
            if(d[p[i].first-1] != p[i].second) ok=false;
        }
        if(ok){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}