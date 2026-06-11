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
    ll n;
    cin >> n;
    P pos[n];
    rep(i,0,n) cin >> pos[i].fs >> pos[i].sc;
    
    map<P,ll> m;
    ll cnt = 0;
    rep(i,0,n){
        rep(j,0,n){
            if(i == j) continue;
            ll dx = pos[i].fs - pos[j].fs;
            ll dy = pos[i].sc - pos[j].sc;
            if(m.count(P(dx,dy)) == 0){
                m[P(dx,dy)] = 1;
                cnt = max(1LL,cnt);
            }
            else{
                m[P(dx,dy)]++;
                cnt = max(m[P(dx,dy)],cnt);
            }
        }
    }

    cout << n - cnt << endl;

    return 0;
}
