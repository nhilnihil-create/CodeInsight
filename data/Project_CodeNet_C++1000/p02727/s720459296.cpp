#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)   
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

int main(){
    ll x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    priority_queue<P,VECP> pq;
    rep(i,0,a){
        ll p;
        cin >> p;
        pq.push(P(p,0));
    }
    rep(i,0,b){
        ll q;
        cin >> q;
        pq.push(P(q,1));
    }
    rep(i,0,c){
        ll r;
        cin >> r;
        pq.push(P(r,2));
    }

    ll cnt = 0,ans = 0,r_cnt = 0,g_cnt = 0;
    while(!pq.empty() && cnt < x+y){
        P p = pq.top();
        pq.pop();
        if(p.sc == 0){
            if(r_cnt < x){
                ans += p.fs; 
                r_cnt++;
                cnt++;
            }
        }
        else if(p.sc == 1){
            if(g_cnt < y){
                ans += p.fs;
                g_cnt++;
                cnt++;
            }
        }
        else {
            ans += p.fs;
            cnt++;
        }
    }
    cout << ans << endl;
    return 0;
}
