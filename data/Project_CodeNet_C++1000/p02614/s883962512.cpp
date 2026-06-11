#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60; //intじゃ扱えないことに注意！
using P = pair<int,int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++) //範囲外参照とループの初期化に注意！

int main() {
    int h,w,k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int ans = 0;
    rep(is,1<<h)rep(js,1<<w){
        int cnt = 0;
        rep(i,h)rep(j,w){
            if(is>>i&1) continue;  //i行目を消す
            if(js>>j&1) continue;  //j列目を消す
            if(s[i][j] == '#') cnt++;
        } 
        if(cnt == k) ans++;
    }
    cout << ans << endl;
    return 0;
}