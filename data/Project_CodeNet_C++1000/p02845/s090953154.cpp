#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#include <numeric>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[8]={ 0, 1, 0,-1, 1, 1,-1,-1}; // x軸方向への変位
ll dy[8]={ 1, 0,-1, 0, 1,-1, 1,-1}; // y軸方向への変位

int main(void){
    ll n;
    cin >> n;
    ll INF = 1e+9+7;
    ll ans = 1;
    ll z = 3, y = 0;
    vector<ll> c(100010, 0);
    for(ll i = 1; i <= n; i++){
        ll a;
        cin >> a;
        if(a==0) ans = ans*(3-c[a])%INF;
        else ans = ans*(c[a-1]-c[a])%INF;
        c[a]++;
    }
    cout << ans << endl;
    return 0;
}
