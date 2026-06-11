#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
    int n; cin >> n;
    vector<vector<pair<int, int>>> a(n);
    rep(i, n){
        int tmp; cin >> tmp;
        a[i].resize(tmp);
        rep(j, tmp){
            cin >> a[i][j].first >> a[i][j].second;
            a[i][j].first --; 
        }
    }
    int ans = 0;
    rep(b, (1<<n)){
        bitset<15> bit(b);
        bool check = true;
        int cnt = 0;
        rep(i, n){
            if (bit.test(i)){
                for (auto ai: a[i]){
                    if (ai.second == 1 && !bit.test(ai.first)) check = false;
                    else if (ai.second == 0 && bit.test(ai.first)) check = false;
                }
            }
        }
        rep(i, n){
            if (b & (1 << i)) cnt ++;
        } 
        if (check) ans = max(ans, cnt);
    }
    cout << ans << endl;
}