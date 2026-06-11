#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int mod = 1000000007;

int main(){
    int n,m;
    cin >> n >> m;
    vector<bool> v(n,false);
    vector<ll> dp(n,0);
    rep(i,m) {
        int a;
        cin >> a;
        a--;
        v.at(a) = true;
    }
    if(!v.at(0)) dp.at(0) = 1;
    if(n > 1 && !v.at(1)) dp.at(1) = dp.at(0) + 1;
    for(int i = 2; i < n;i++){
        if(v.at(i)) continue;
        dp.at(i) = (dp.at(i-1) + dp.at(i-2)) % mod;
    }
    cout << dp.at(n-1) << endl;

}