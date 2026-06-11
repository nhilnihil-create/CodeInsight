#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1'000'000'007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ll n;   cin >> n;
    vector<ll> p, q;
    vector<pair<ll, ll>> point(n);
    map<pair<ll, ll>, ll> key;
    REP(i, n) {
        cin >> point[i].first >> point[i].second;
        key[point[i]] += 1; 
    }
    sort(ALL(point));
    vector<pair<ll, ll>> arg;
    REP(i, n){
        FOR(j, i+1, n){
            arg.emplace_back(point[i].first-point[j].first, point[i].second-point[j].second);
        }
    }
    ll res=LINF;
    if(0<arg.size()){
        REP(k, arg.size()){
            ll dx = arg[k].first, dy=arg[k].second, tmp=0;
            REP(i, n){
                ll x=point[i].first, y=point[i].second;
                if(!key.count({x-dx, y-dy})){
                    tmp += 1;
                }
            }
            res = min(res, tmp);
        }
    }else res=1;
    cout << res << endl;
}
