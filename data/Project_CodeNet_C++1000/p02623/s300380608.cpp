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

    ll n, m, k; cin >> n >> m >> k;
    ll a[n], b[m];
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    ll know = 0;
    ll cnt = 0;
    ll ia = -1;
    rep(i, n){
        if(know + a[i] > k){
            ia = i - 1;
            break;
        }

        know += a[i];
        cnt++;
    }

    if(ia == -1) ia = n - 1;

    ll cntmax = cnt;
    // cout << "know: " << know << ", ";
    // cout << "(ia, ib): " << ia << ", " << 0 << endl;
    // cout << "  cnt: " << cnt << endl;
    bool is_finished = false;
    rep(ib, m){
        if(know + b[ib] <= k){
            know += b[ib];
            cnt++;
            cntmax = max(cnt, cntmax);
            // cout << "know: " << know << ", ";
            // cout << "(ia, ib): " << ia << ", " << ib << endl;
            // cout << "  cnt: " << cnt << endl;
        }
        else{
            know += b[ib];
            cnt++;
            // cout << "know: " << know << ", ";
            // cout << "(ia, ib): " << ia << ", " << ib << endl;
            while(know > k){
                if(ia == -1){
                    is_finished = true;
                    break;
                }
                know -= a[ia];

                ia--;
                cnt--;

                // cout << "know: " << know << ", ";
                // cout << "(ia, ib): " << ia << ", " << ib << endl;
            }

            if(!is_finished){
                cntmax = max(cnt, cntmax);
            }
            // cout << "  cnt: " << cnt << endl;
        }

        if(is_finished) break;
    }

    cout << cntmax << endl;


    return 0;
}