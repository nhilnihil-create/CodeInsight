#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> llVEC;
typedef vector<P> PVEC;
typedef priority_queue<P,PVEC,greater<P> > PPQ;
typedef priority_queue<ll, llVEC, greater<ll> > llPQ;

#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n-1; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue;
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

template<typename T>
ll sz(vector<T> &vec){ return (ll)vec.size(); }
ll sz(string &s){ return (ll)s.size(); }
ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }
ll lcm(ll a,ll b){ return a / gcd(a,b) * b; }

int main(){
    ll a[3][3] = {},b[3][3] = {};
    rep(i,0,3) rep(j,0,3) cin >> b[i][j];
    
    ll n;
    cin >> n;
    rep(i,0,n){
        ll x;
        cin >> x;
        rep(j,0,3){
            rep(k,0,3){
                if(b[j][k] == x) a[j][k] = 1;
            }
        }
    }

    bool flag = false;
    rep(i,0,3) if(a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] == 1) flag = true;
    rep(i,0,3) if(a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i] == 1) flag = true;
    if(a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[1][1] == 1) flag = true;
    if(a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[1][1] == 1) flag = true;
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
