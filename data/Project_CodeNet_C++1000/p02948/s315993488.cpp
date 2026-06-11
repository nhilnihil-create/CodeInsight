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
ll sz(vector<T> vec){ return (ll)vec.size(); }
ll sz(string s){ return (ll)s.size(); }

ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }


int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> vec[m+1];
    ll a[n],b[n];
    rep(i,0,n){
        cin >> a[i] >> b[i];
        if(m-a[i] >= 0) vec[m-a[i]].push_back(i);
    }

    priority_queue<ll, llVEC> pq;
    ll ans = 0;
    rrep(i,0,m+1){
        rep(j,0,sz(vec[i])){
            pq.push(b[vec[i][j]]);
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;
    return 0;
}