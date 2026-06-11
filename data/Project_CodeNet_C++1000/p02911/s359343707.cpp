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
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> point(n, k);
    vector<int> correct(n, 0);
    int person;
    REP(i,q){
        cin>>person;
        correct[person-1]++;
    }
    REP(i,n){
        if(point[i]+correct[i]-q<=0){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        };
    }

    return 0;
}
