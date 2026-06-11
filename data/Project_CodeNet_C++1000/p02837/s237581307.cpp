#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
vector<vector<pair<int, int>>> a;

bool judge(int bit, int n){
    rep(i, n){
        if (!(bit & (1 << i))) continue;
        for(auto xy:a[i]){
            int x, y; tie(x, y) = xy;
            if (y == 1 && !(bit & (1 << x))) return false;
            if (y == 0 && (bit & (1 << x))) return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    a.resize(n);
    rep(i, n){
        int tmp; cin >> tmp;
        a[i].resize(tmp);
        rep(j, tmp){
            cin >> a[i][j].first >> a[i][j].second;
            a[i][j].first --;
        }
    }
    int res = 0;
    for (int bit = 0; bit < (1 << n); bit++){
        if (judge(bit, n)){
            int cnt = 0;
            rep(i, n){
                if (bit & (1<<i)) cnt++;
            }
            res = max(cnt, res);
        }
    }
    cout << res << endl;
}   
