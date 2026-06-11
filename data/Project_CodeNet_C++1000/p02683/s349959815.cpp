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

    ll n, m, x;
    cin >> n >> m >> x;

    ll c[n], a[n][m];
    rep(i, n){
        cin >> c[i];
        rep(j, m){
            cin >> a[i][j];
        }
    }

    ll cost_min = 1e18;
    ll asum[m];
    ll cnt = 1;

    while(cnt <= pow(2, n)){

        rep(j, m){
            asum[j] = 0;
        }

        ll cnt_temp = cnt;
        ll cost = 0;
        rep(i, n){
            if(cnt_temp % 2 == 1){
                cost += c[i];
                rep(j, m){
                    asum[j] += a[i][j];
                }
            }
            cnt_temp /= 2;
        }

        bool is_cleared = true;
        rep(j, m){
            if(asum[j] < x){
                is_cleared = false;
                break;
            }
        }

        if(is_cleared){
            if(cost < cost_min){
                cost_min = cost;
            }
        }

        cnt++;
    }


    if(cost_min > 1e9){
        cout << -1 << endl;
    }
    else{
        cout << cost_min << endl;
    }


    return 0;
}