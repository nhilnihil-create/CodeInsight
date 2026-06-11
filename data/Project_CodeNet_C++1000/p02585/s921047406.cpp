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
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n), c(n);
    REP(i, n){
        cin >> p[i];
        p[i]--;
    }
    REP(i, n){
        cin >> c[i];
    }
    ll ans = -INF;
    REP(i, n){
        ll sum = 0, loop = 0;
        {
            ll now = i;
            REP(j, n){
                sum += c[now];
                now = p[now];
                loop++;
                if(now == i) break;
            }
        };
        ll now = i, cnt = 0, s = 0;
        REP(j, min(k, loop)){
            cnt++;
            s += c[now];
            ans = max(ans, max(sum, 0LL) * ((k - cnt) / loop) + s);
            now = p[now];
        }
    }
    cout << ans << endl;
}