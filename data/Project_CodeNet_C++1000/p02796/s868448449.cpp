#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cstring>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for(long long i=0; i<n; i++)
#define reps(i, s, e) for(long long i=s; i<e; i++)
#define repr(i, n) for(long long i=n-1; i>=0; i--)
#define reprs(i, s, e) for(long long i=e-1; i>=s; i--)

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n; cin >> n;
    ll x[n], l[n];
    rep(i, n){
        cin >> x[i] >> l[i];
    }

    pair<ll, ll> p[n];
    rep(i, n){
        p[i] = {x[i] + l[i], x[i] - l[i]};
    }

    sort(p, p + n);

    ll ans = 0;
    ll pos = -1e18;

    rep(i, n){
        ll start = p[i].second;
        ll end = p[i].first;

        if(pos <= start){
            ans++;
            pos = end;
        }
    }

    cout << ans << endl;
    
    return 0;
}