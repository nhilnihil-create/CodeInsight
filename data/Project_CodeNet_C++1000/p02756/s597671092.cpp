#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a-1; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(){
    string s;   cin >> s;
    ll q, state=0;   cin >> q;
    rep(i, q){
        ll op;  cin >> op;
        if(op==1){
            state = !state;
        }else{
            ll a;
            char c; cin >> a >> c;
            a--;
            if(state) a = !a;
            if(!a) s = c+s;
            else s += c;
        }
    }
    if(state) reverse(ALL(s));
    cout << s << endl;
}
