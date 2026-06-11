#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <iomanip>  //setprecision(桁)
using namespace std;
#define pb push_back
#define ll long long int
#define rep(i,n) for(int i = 0;i < (n);i++)
ll INF = 1000000010; 
const ll MOD = 1000000007;


int main(){
    int n, m; cin >> n >> m;
    vector<pair<int,int>> key;

    rep(i,m){
        int a, b; cin >> a >> b;
        int s = 0;
        rep(j,b){
            int c; cin >> c;
            c--;
            s |= (1<<c);
        }
        key.emplace_back(s,a);
    }

    vector<ll> dp(1<<n,INF);
    dp[0] = 0;

    rep(i, (1<<n)){
        rep(j, m){
            int t = i | key[j].first;
            ll cost = dp[i] + key[j].second;
            dp[t] = min(dp[t],cost);
        }
    }
    ll ans = dp.back();
    if(ans == INF) ans = -1;
    cout << ans << endl;
}