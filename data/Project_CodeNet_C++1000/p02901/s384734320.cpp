#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> cost(m);
    vector<vector<bool>> opens(m, vector<bool>(n));
    rep(i,m){
        int a,b;
        cin >> cost.at(i) >> b;
        rep(j,b){
            int c;
            cin >> c;
            opens.at(i).at(c-1) = true;
        }
    }
    map<vector<bool>,int> mp;
    for(int bits=0;bits<(1<<n);bits++){
        vector<bool> v(n);
        for(int i=0;i<n;i++){
            if(bits & (1<<i)){
                v.at(i) = true;
            }
            else {
                v.at(i) = false;
            }
        }
        mp[v] = bits;
    }

    vector<int> keycd(m);
    rep(i,m){
        keycd.at(i) = mp[opens.at(i)];
    }

    vector<int> dp(1<<n);
    rep(i,dp.size()){
        dp.at(i) = INF;
    }
    dp.at(0) = 0;

    rep(i,m){
        for(int bits=0;bits<(1<<n);bits++){
            if(dp.at(bits) == INF) continue;
            int nc = bits | keycd.at(i);
            int nm = dp.at(bits) + cost.at(i);
            dp.at(nc) = min(dp.at(nc),nm);
        }
    }
    int allopened = (1<<n)-1;
    if(dp.at(allopened) == INF) dp.at(allopened) = -1;
    cout << dp.at(allopened) << endl;
    return 0;
}