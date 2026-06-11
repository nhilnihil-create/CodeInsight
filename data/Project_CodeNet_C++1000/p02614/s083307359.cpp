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

    ll h, w, k; cin >> h >> w >> k;
    string mat[h];
    rep(i, h){
        cin >> mat[i];
    }

    ll ans = 0;
    ll maxb = pow(2, h + w);
    bool rows[h], cols[w];
    rep(b, maxb){
        ll btemp = b;
        rep(i, h){
            rows[i] = (btemp % 2 == 1) ? true : false;
            btemp >>= 1;
        }
        rep(i, w){
            cols[i] = (btemp % 2 == 1) ? true : false;
            btemp >>= 1;
        }

        // rep(i, h){
        //     cout << rows[i] << " ";
        // }
        // rep(i, w){
        //     cout << cols[i] << " ";
        // }
        // cout << endl;

        ll cnt = 0;
        rep(i, h){
            if(rows[i] == false) continue;

            rep(j, w){
                if(cols[j] == false) continue;

                if(mat[i][j] == '#') cnt++;
            }
        }

        if(cnt == k) ans++;
    }

    cout << ans << endl;

    return 0;
}