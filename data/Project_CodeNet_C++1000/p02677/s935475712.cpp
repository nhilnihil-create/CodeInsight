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

int main(){
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    double th = double(h*60+m)/720 * 2*PI;
    double tm = double(m)/60 *2*PI;
    double xh = a*cos(th), yh = a*sin(th);
    double xm = b*cos(tm), ym = b*sin(tm);
    double dx = xh-xm, dy = yh-ym;
    double ans = sqrt(dx*dx + dy*dy);
    printf("%.10f\n", ans);
    return 0;
}