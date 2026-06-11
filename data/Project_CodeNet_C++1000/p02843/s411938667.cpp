#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
#define INF 1e10
typedef long long ll;
typedef long double ld;
int main(){
    string x;
    cin>>x;
    string head, tail;
    ll n=SIZE(x);
    if(n<3){
        cout<<0<<endl;
    }else{
        head=x.substr(0,n-2), tail=x.substr(n-2,2);
        ll head_num=stoll(head), tail_num=stoll(tail);
        cout<<((head_num*5>=tail_num)?1:0)<<endl;
    }
    return 0;
}
