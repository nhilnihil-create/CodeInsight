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
    map<p, ll> I{};
    vector<p> vp;
    for(ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        vp.push_back(p(a, b));
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            if(i==j) continue;
            ll a = vp[i].first-vp[j].first;
            ll b = vp[i].second-vp[j].second;
            I[p(a, b)]++;
        }
    }
    ll ans = 0;
    ll MAX = 0;
    for(auto x : I)
        MAX = max(MAX, x.second);
    //cout << MAX << endl;
    cout << n-MAX << endl;
    return 0;
}
