#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;

int main(){
    string s;
    cin>>s;
    int n;
    if(s=="SUN"){
        n=7;
    }else if(s=="MON"){
        n=6;
    }else if(s=="TUE"){
        n=5;
    }else if(s=="WED"){
        n=4;
    }else if(s=="THU"){
        n=3;
    }else if(s=="FRI"){
        n=2;
    }else if(s=="SAT"){
        n=1;
    }
    cout<<n;
    return 0;
}
