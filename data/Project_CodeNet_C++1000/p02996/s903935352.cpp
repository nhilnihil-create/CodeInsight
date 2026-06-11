#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;

signed main(){
    ll n;
    cin >> n;
    pair<P,ll> p[n];
    ll time[n] = {},memo = 0;

    rep(i,0,n){
        ll a,b;
        cin >> a >> b;
        p[i] = pair<P,ll>(P(b,a),i);
    }

    sort(p,p+n);

    rep(i,0,n){
        time[p[i].sc] = (memo += p[i].fs.sc);

    }

    rep(i,0,n){
        if(time[p[i].sc] > p[i].fs.fs){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}