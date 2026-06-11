#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <iomanip>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;

int main(){
    ll a,b,x;
    cin>>a>>b>>x;
    long double y;
    if(x>a*a*b/2){
        y=1000000000*2*(a*a*b-x)/(a*a*a);
    }else{
        y=1000000000*(a*b*b)/(2*x);
    }
    cout << fixed << setprecision(7) << atan(y/1000000000)*180/M_PI;
    return 0;
}
