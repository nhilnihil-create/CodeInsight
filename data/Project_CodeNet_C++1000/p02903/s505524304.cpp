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
    ll h, w, a, b;
    cin >> h >> w >> a >> b;
    vector<vector<ll>> ans(h, vector<ll>(w, 0));
    for(ll i = 0; i < h; i++){
        for(ll j = 0; j < w; j++){
            if(i < b && j < a) ans[i][j] = 1;
            if(i < b && j >= a) ans[i][j] = 0;
            if(i >= b && j < a) ans[i][j] = 0;
            if(i >= b && j >= a) ans[i][j] = 1;
        }
    }
    for(ll i = 0; i < h; i++){
        for(ll j = 0; j < w; j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
