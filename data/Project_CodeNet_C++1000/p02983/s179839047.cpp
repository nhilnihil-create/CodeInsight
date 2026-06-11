#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i, n) for(ll i = 0; i < n; i++)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;
typedef long double ld;
int main(){
    ll l,r,a,b;
    cin>>l>>r;
    if(r-l+1>=2019){
        cout<<0;
    }else{
        ll min=2018;
        FOR(i,l,r){
            FOR(j,i+1,r+1){
                ll value=(i*j)%2019;
                if(min>value){
                    min=value;
                }
                if(min==0){
                    break;
                }
            }
            if(min==0){
                break;
            }
        }
        cout<<min;
    }
    return 0;
}
