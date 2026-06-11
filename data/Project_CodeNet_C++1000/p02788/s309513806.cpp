#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

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
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

template<typename T>
ll sz(vector<T> &vec){ return (ll)vec.size(); }
template<typename T>
ll sz(priority_queue<T, vector<T>> &pq) {return (ll)pq.size(); }
template<typename T>
ll sz(priority_queue<T, vector<T>, greater<T>> &pq) {return (ll)pq.size(); }
ll sz(string &s) {return (ll)s.size(); } 
ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }
ll lcm(ll a,ll b){ return a / gcd(a,b) * b; }
bool checkindex(ll i,ll n){ return (i < n && i >= 0); }

#define SEG_LEN (1 << 19)

ll seg[SEG_LEN*2];

ll get(ll ind){
    ll res = 0;
    ind += SEG_LEN;
    res += seg[ind];
    while(1){
        ind /= 2;
        if(ind <= 0) break;
        res += seg[ind];
    }
    return res;
}

void add(ll l, ll r,ll v){
    l += SEG_LEN; r += SEG_LEN;
    while(l < r){
        if(l % 2 == 1){
            seg[l] += v;
            l++;
        }
        l /= 2;
        
        if(r % 2 == 1){
            seg[r-1] += v;
            r--;
        }
        r /= 2;
    }
}

int main(){
    ll n,d,a;
    cin >> n >> d >> a;

    P p[n];
    rep(i,0,n){
        cin >> p[i].fs >> p[i].sc;
    }
    sort(p,p+n);

    rep(i,0,n) add(i+1,i+2,p[i].sc);

    ll ans = 0;
    rep(i,0,n){
        ll ok = i,ng = n;
        while(abs(ok-ng) > 1){
            ll mid = (ok+ng)/2;
            if(p[mid].fs <= p[i].fs + 2*d){
                ok = mid;
            }
            else{
                ng = mid;
            }
        }

        if(get(i+1) > 0){
            ll temp = a*(ll)ceil((double)get(i+1)/a);
            ans += temp/a;
            add(i+1,ok+2,-temp);
        }
    }
    cout << ans << endl;
    return 0;
}

