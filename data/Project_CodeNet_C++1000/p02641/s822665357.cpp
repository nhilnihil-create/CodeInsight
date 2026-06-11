#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60; //intじゃ扱えないことに注意！
using P = pair<int,int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++) //範囲外参照とループの初期化に注意！

int main() {
    int X,N;
    cin >> X >> N;
    vector<bool> ok(102);
    rep(i,102) ok[i] = true;
    rep(i,N){
        int p;
        cin >> p;
        ok[p] = false;
    }
    P ans(99999,-1);  //()のなかは初期化
    for(int i = 0; i <= 101; i++){
        if(!ok[i]) continue;
        int dis = abs(X-i);
        ans = min(ans,P(dis,i));   //pair同士の比較ではfirstが先に比較され、次にsecond
    }  //ans を別のpairで置き換えてる
    cout << ans.second << endl;
    return 0;
}