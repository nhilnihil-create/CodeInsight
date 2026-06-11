#include <bits/stdc++.h> //全てのヘッダファイルをインクルード
 
//ループ
#define rep(i, n) for(int i = 0; i < (n); i++) //普通のループ
#define repr(i, n) for(int i = n; i >= 0; i--) //逆ループ
 
//型名省略
typedef long long ll;
//値
static const ll MX = 100005;
static const ll MX_ll = 1e18;
const double PI = acos(-1); //π
 
using namespace std;
 
//ソート
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
 
//#include "./lib/generic/search.h"

//文字列入力した小数値を小数点なくして返す
int changeDoubleToInt(string decimal){ 
    decimal.erase(1, 1); //小数点削除
    int n_decimal = atoi(decimal.c_str()); //c_strでchar*に変換後、atoiでintに変換
    return n_decimal;
}

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    int c[n], a[n][m];
    rep(i, n){
        cin >> c[i];
        rep(j, m){
            cin >> a[i][j];
        }
    }
    int ans = 1001001001;

    rep(s, 1<<n){ //sは0-nの値まで1bitずつ数が増えていく(<<で1ビットずつビットシフトしているため)
        int cost = 0;
        vector<int> d(m);
        rep(i, n){ 
            if(s>>i&1){ // sのibit=1のとき＝i番目の本を選ぶことになる
                cost += c[i]; //costを求める
                rep(j,m) d[j] += a[i][j];
            }
        }

        bool ok = true;
        rep(j,m) if(d[j] < x) ok = false; //xを超えないものがあったらNGとする
        if(ok) ans = min(ans, cost);
    }

    if(ans==1001001001) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}