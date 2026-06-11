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

    ll n, k; cin >> n >> k;

    ll a[n];
    rep(i, n){
        cin >> a[i];
        a[i]--;
    }

    ll p[n];
    memset(p, -1, sizeof(p));

    ll pos = 0;
    p[0] = 0;
    bool is_period_checked = false;
    reps(t, 1, k + 1){
        pos = a[pos];
        // cout << "t: " << t << ", pos " << pos + 1 << endl;

        if(p[pos] == -1){
            p[pos] = t;
        }
        else if(!is_period_checked){
            ll period = t - p[pos];
            // cout << "period " << period << endl;

            ll n_loop_to_skip = (k - t) / period;
            t += n_loop_to_skip * period;

            is_period_checked = true;
        }
    }

    cout << pos + 1 << endl;

    return 0;
}