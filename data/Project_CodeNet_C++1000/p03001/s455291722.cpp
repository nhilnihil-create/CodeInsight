
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

//与えられた(x,y)から中心を通るように直線を引けば半分ずつに分割出来る
//(x,y)自体が中心の場合はそこからどのように直線を引いてもOK
int main(){
    ll w, h, x, y;
    cin >> w >> h >> x >> y;
    double ans=(double)w*h/2;
    int num=0;
    if(w==x*2 && h==y*2) num = 1;

    cout << setprecision(10) << ans << ' ' << num << endl;


}