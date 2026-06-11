#include <bits/stdc++.h>
#include <cstdlib>  //abs()で絶対値を取得する（整数）
#include <cmath>    //abs()かfabs()で絶対値を取得する（少数）
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main(){
    int h, n, a;
    int b = 0;
    cin >> h >> n;
    rep (i,n){
        cin >> a;
        b = b + a;
    }
    if (b >= h){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}