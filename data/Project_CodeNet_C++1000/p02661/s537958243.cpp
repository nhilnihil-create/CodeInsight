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
    ll n;
    cin >> n;
    ll a[n],b[n];
    rep(i,0,n){
        cin >> a[i] >> b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    
    if(n % 2 == 0) cout << b[n/2]+b[n/2-1]-(a[n/2]+a[n/2-1]) + 1 << endl;
    else cout << b[n/2] - a[n/2] + 1 << endl;

    return 0;
}