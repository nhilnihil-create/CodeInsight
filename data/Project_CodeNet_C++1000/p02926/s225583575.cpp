#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <assert.h>
#include <unordered_set>
#include <random>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)





















int main(){
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    vector<pair<double, ll>> r(n);
    REP(i, n){
        cin >> x[i] >> y[i];
        double res = atan2(y[i], x[i]);
        if(res < 0){
            res = 2.0 * acos(-1) + res;
        }
        r[i] = {res, i};
    }
    sort(r.begin(), r.end());
    long double ans = 0.0;
    REP(i, n){
        REP(j, n){
            ll sx = 0, sy = 0;
            if(i <= j){
                for(ll k = i; k <= j; k++){
                    sx += x[r[k].second];
                    sy += y[r[k].second];
                }
            }
            else{
                for(ll k = i; k <= j + n; k++){
                    sx += x[r[k % n].second];
                    sy += y[r[k % n].second];
                }
            }
            ans = max(ans, sqrt((long double)(sx * sx + sy * sy)));
        }
    }
    printf("%.12Lf\n", ans);
}