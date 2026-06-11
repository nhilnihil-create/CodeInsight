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
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 1;
    ll INF = 1e+9+7;
    vector<ll> c(n+1, 0);
    for(ll i = 0; i < n; i++){
        ll b = a[i];
        if(b==0) ans*=(3-c[b]);
        else ans*=(c[b-1]-c[b]);
        ans%=INF;
        c[b]++;
    }
    cout << ans << endl;
    return 0;
}
