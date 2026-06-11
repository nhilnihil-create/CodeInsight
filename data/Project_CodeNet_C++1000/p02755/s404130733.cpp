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

//最大公約数
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
   int a, b;
   cin >> a >> b;
   rep(i, 10000){
       int za = i*8/100;
       int zb = i*10/100;
       if(za==a && zb==b){
           cout << i << endl;
           return 0;
       }
   }
   cout << "-1" << endl;
   return 0;
}