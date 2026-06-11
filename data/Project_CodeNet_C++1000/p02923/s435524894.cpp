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
    ll n;
    cin>>n;
    vector<ll> v(n);
    REP(i,n){
        cin>>v[i];
    }
    ll count=0, max=0;
    REP(i,n-1){
        ll left=v[i],right=v[i+1];
        if(left>=right){
            count++;
        }else if(max<count){
            max=count;
            count=0;
        }else{
            count=0;
        }
    }
    if(max<count){
        max=count;
    }
    cout<<max;
    return 0;
}
