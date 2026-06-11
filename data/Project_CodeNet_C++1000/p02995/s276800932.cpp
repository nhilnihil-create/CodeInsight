#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;
typedef long double ld;

ll gcd(ll a, ll b){
    if(a%b==0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}

int main(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    //最小公倍数
    ll l=c*d/gcd(c,d),
    //1からc-1について
    p1=(a-1)/c, q1=(a-1)/d, r1=(a-1)/l,
    //1からdについて
    p2=b/c, q2=b/d, r2=b/l,
    //cからdについて
    p3=p2-p1, q3=q2-q1, r3=r2-r1,
    //cからdの幅
    wid=b-a+1;
    cout<<wid-p3-q3+r3;
    return 0;
}
