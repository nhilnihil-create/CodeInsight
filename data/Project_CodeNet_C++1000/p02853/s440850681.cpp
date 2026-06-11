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

int main(void) {
    ll x, y;
    cin >> x >> y;
    vector<ll> a(1000, 0);
    a[1] = 300000;
    a[2] = 200000;
    a[3] = 100000;
    ll ans = a[x]+a[y];
    if(x==1&&y==1) ans += 400000;
    cout << ans << endl;
    return 0;
}
