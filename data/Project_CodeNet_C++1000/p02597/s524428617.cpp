#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define chmax(x, y) { x = max(x, y); }
#define chmin(x, y) { x = min(x, y); }
#define INF 1e7

int main() {
    int n;
    cin >> n;
    st c;
    cin >> c;
    int rsum = 0;
    rep(i, n){
        if(c.at(i) == 'R'){
            rsum++;
        }
    }
    int ans = 0;
    rep(i, rsum){
        if(c.at(i) == 'W'){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}