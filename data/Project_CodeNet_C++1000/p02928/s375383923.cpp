#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#include <iomanip>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};

int main(void){
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for(ll i = 0; i < n; i++)
        cin >> a[i];
    ll check = 0;
    for(ll i = 0; i < n-1; i++){
        for(ll j = i+1; j < n; j++){
            if(a[i]>a[j]) check++;
        }
    }
    ll f = 0;
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++)
        if(a[i] > a[j]) f++;
    //cout << check << " " << f << endl;
    ll INF = 1e+9+7;
    ll ans;
    ans = (check*k%INF+((k-1)*k/2)%INF*f%INF)%INF;
    cout << ans << endl;
    return 0;
}
