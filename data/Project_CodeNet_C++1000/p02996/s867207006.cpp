#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    map<ll, ll> mp;
    rep(i, N){
        ll a, b;
        cin >> a >> b;
        mp[b] += a;
    }
    ll time = 0;
    bool is = true;
    for(auto p : mp){
        if(time + p.second > p.first){
            is = false;
            break;
        }
        time += p.second;
    }
    if(is) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}