#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;


int main(){
    ll n;
    cin >> n;
    vector<ll>p(n);
    rep(i,n){
        cin>>p[i];
        p[i]--;
    }
    vector<ll>idx(n);
    rep(i,n){
        idx[p[i]]=i;
    }
    set<ll>s;
    ll ans = 0;
    for(ll i=n-1;i>=0;i--){
        int x = idx[i];
        s.insert(x);
        auto it = s.find(x);
        vector<ll>l(2,-1);
        rep(j,2){
            if(it==s.begin())break;
            it--;
            l[j]=*it;
        }
        it = s.find(x);
        vector<ll>r(2,n);
        rep(j,2){
            it++;
            if(it==s.end())break;
            r[j]=*it;
        }
        
        ll c;
        c = (x-l[0])*(r[1]-r[0])+(r[0]-x)*(l[0]-l[1]);
        c *= (i+1);
        ans += c;
    }
    cout << ans << endl;
    return 0;
}