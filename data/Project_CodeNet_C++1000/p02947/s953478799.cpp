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
    vector<char> inner(10);
    vector<vector<char>> outer;
    REP(i,n){
        REP(j,10){
            cin>>inner[j];
        }
        sort(ALL(inner));
        outer.push_back(inner);
    }
    sort(ALL(outer));
    ll count=0;
    ll sum=0;
    REP(i,n){
        if(outer[i]==outer[i+1]){
            count++;
        }else{
            sum+=count*(count+1)/2;
            count=0;
        }
    }
    cout<<sum;
    return 0;
}
