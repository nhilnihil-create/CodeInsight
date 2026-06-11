#include <bits/stdc++.h>
#include <cstdlib>  //abs()で絶対値を取得する（整数）
#include <cmath>    //abs()かfabs()で絶対値を取得する（少数）
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main(){
    int s;
    int w;
    cin >> s >> w;
    if (s <= w){
        cout << "unsafe";
    }else{
        cout << "safe";
    }
    return 0;
}