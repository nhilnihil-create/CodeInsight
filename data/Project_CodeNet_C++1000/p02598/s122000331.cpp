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
    vector<ll> a(n);
    REP(i, n){
        cin >> a[i];
    }
    ll down = 0, up = INF;
    while(up - down > 1){
        ll mid = (up + down) / 2;
        ll cnt = 0;
        REP(i, n){
            cnt += ((a[i] % mid == 0)? a[i] / mid : a[i] / mid + 1) - 1;
        }
        ((cnt > k)? down : up) = mid;
    }
    cout << up << endl;
}