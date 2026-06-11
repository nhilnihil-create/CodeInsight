#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1'000'000'007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a-1; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define rALL(x) x.rbegin(), x.rend()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    string s;   cin >> s;
    ll n;       cin >> n;
    vector<ll> v;
    ll cnt=0;
    FOR(i, 1, s.size()){
        if(s[i-1]==s[i]) cnt += 1;
        else{
            v.push_back(cnt+1);
            cnt = 0;
        }
    }
    if(0<cnt) v.push_back(cnt+1);
    
    ll res = n/2;
    if(1<v.size()){
        res = 0;
        if(s[0]!=s.back()){
            rep(i, v.size()) res += v[i]/2*n;
        }else{
            res = *v.begin()/2+v.back()/2 + (*v.begin()+v.back())/2*(n-1);
            FOR(i, 1, v.size()-1) res += v[i]/2*n;
        }
        
    }else if(0<v.size()) res = v.back()*n/2;

    cout << res << endl;
}