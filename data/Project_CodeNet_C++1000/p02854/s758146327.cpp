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
    ll s[n];
    ll c = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        c+=a[i];
        if(i==0) s[i] = a[i];
        else s[i] = s[i-1] + a[i];
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        //if(s[i]*2==c) break:
        if(s[i]*2>c){
            ans = min(s[i]-(c-s[i]), (c-s[i-1])-s[i-1]);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
