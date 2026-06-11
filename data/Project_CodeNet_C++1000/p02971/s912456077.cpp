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
    ll n;
    cin>>n;
    vector<ll> v(n);
    REP(i,n){
        cin>>v[i];
    }
    ll max=MAX(v), second=0;
    ll count=0;
    REP(i,n){
        if(v[i]==max){
            count++;
        }
        if(v[i]!=max&&second<v[i]){
            second=v[i];
        }
    }
    if(count>1){
        REP(i,n){
            cout<<max<<endl;
        }
    }else{
        REP(i,n){
            if(v[i]==max){
                cout<<second<<endl;
            }else{
                cout<<max<<endl;
            }
        }
    }
    return 0;
}
