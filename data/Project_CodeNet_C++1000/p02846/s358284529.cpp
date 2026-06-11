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
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    ll p = (a1 - b1) * t1, q = (a2 - b2) * t2;
    if(p > 0){
        p *= -1;
        q *= -1;
    }
    if(p + q < 0){
        cout << 0 << endl;
        return 0;
    }
    if(p + q == 0){
        cout << "infinity" << endl;
        return 0;
    }
    ll s = -p / (p + q);
    ll t = -p % (p + q);
    cout << s * 2 + (t != 0) << endl;
}