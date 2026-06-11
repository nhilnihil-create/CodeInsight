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
    int n;
    cin>>n;
    vector<int> d(n);
    REP(i,n){
        cin>>d[i];
    }
    int sum=0;
    REP(i,n-1){
        FOR(j,i+1,n){
            sum+=d[i]*d[j];
        }
    }
    cout<<sum;
    return 0;
}
