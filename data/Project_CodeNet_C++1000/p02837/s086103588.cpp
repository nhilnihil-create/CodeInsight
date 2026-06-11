#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 MOD = 1e9 + 7;
const i64 INF = i64(1e18) + 7;


template <typename T>
bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}


signed main(){
    int n;
    cin >> n;
    vector<vector<int>> x(n);
    vector<vector<int>> y(n);
    for(int i = 0; i < n; ++i){
        int m;
        cin >> m;
        x[i].resize(m);
        y[i].resize(m);
        for(int j = 0; j < x[i].size(); ++j){
            cin >> x[i][j] >> y[i][j];
            --x[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < (1 << n); ++i){
        int cnt = 0;
        bitset<15> fl, fl2, fl3;
        fl3 = bitset<15>(i);
        for(int j = 0; j < n; ++j){
            if(i & (1 << j)){
                for(int k = 0; k < x[j].size(); ++k){
                    if(y[j][k])
                        fl.set(x[j][k]);
                    else
                        fl2.set(x[j][k]);
                }
                ++cnt;
            }
        }
        if((fl & fl3) == fl && (fl & ~fl3) == 0 && !(fl3 & fl2).any())
            chmax(ans, cnt);
    }
    cout << ans << endl;
}
