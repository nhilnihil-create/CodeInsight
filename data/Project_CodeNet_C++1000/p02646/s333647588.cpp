/*
１秒毎に変化する距離は v - wである
v - wが負であるならば, 鬼は絶対に相手に追いつけない

v  > wのとき:
1sごとに, 鬼と相手の距離は v - wだけ縮まる.
t秒間では, t * (v-w)だけ鬼と相手の距離は縮まる
t * (v-w)が, もともとの距離の差, |a-b|以上であれば鬼は相手に追いつける
そうでなければ, 鬼は相手に追いつけない.
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    
    long long  a, v;
    cin >> a >> v;
    
    long long b, w;
    cin >> b >> w;
    
    long long t;
    cin >> t;
    
    if (w >= v){
        cout << "NO" << endl;
        return 0;
    }
    
    // 浮動小数点の演算を回避する
    if (abs(a-b) <= (v-w) * t){ // ここで()*tがint型の最大値を越える可能性に注意せよ
        cout << "YES" << endl;
        return 0;
    }
    else{
        cout << "NO" << endl;
        return 0;
    }
}
