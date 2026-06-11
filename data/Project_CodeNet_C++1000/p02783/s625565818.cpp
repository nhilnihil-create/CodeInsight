#include <bits/stdc++.h>
#include <cstdlib>  //abs()で絶対値を取得する（整数）
#include <cmath>    //abs()かfabs()で絶対値を取得する（少数）
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main(){
    int h, a;
    cin >> h >> a;
    int b = h % a;
    int c = h / a;
    if (b == 0){
        cout << c << endl;
    }
    if (b != 0){
        int ans = c+1;
        cout << ans << endl;
    }
}