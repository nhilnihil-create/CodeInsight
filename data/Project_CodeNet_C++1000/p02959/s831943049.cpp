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
    vector<ll> a(n+1),b(n);
    ll sum1=0;
    REP(i,n+1){
        cin>>a[i];
        sum1+=a[i];
    }

    REP(j,n){
        cin>>b[j];
    }

    REP(i,n){
        if(a[i]-b[i]>0){
            a[i]-=b[i];
        }else{
            if(a[i+1]-(b[i]-a[i])>0){
                a[i+1]-=b[i]-a[i];
                a[i]=0;
            }else{
                a[i]=0;
                a[i+1]=0;
            }
        }
    }
    ll sum2=0;
    REP(i,n+1){
        sum2+=a[i];
    }
    cout<<sum1-sum2;
    return 0;
}
