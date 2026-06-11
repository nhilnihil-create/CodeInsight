#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
const int INF = 1e18;

signed main(){
    int n, k; cin >> n >> k;
    vector<int> a(n), f(n);
    REP(i,n) cin >> a[i];
    REP(i,n) cin >> f[i];
    sort(all(a));
    sort(rall(f));
    int ok = INF, ng = -1;
    while(ok-ng > 1){
        int mid = (ok+ng)/2;
        int count = 0;
        REP(i,n){
            if(a[i]*f[i] > mid) count += a[i]- mid/f[i];
        }
        if(count > k) ng = mid;
        else ok = mid;
    }
    cout << ok << endl;
}