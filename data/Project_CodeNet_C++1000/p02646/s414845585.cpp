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
int main(){
    ll a,v,b,w,t;
    cin>>a>>v>>b>>w>>t;
    bool is=false;
    if(a>b&&a-b<=(v-w)*t){
        is=true;
    }
    if(a<b&&b-a<=(v-w)*t){
        is=true;
    }
    if(is){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}
