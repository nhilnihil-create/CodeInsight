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
    ll n, k, s;
    cin >> n >> k >> s;
    vector<ll> ans;
    if(s!=1e+9){
        for(ll i = 1; i <= n; i++){
            if(i<=k) ans.push_back(s);
            else ans.push_back(1e+9);
        }
    }
    else{
        for(ll i = 1; i <= n; i++){
            if(i<=k) ans.push_back(s);
            else ans.push_back(1);
        }
    }
    for(ll i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
