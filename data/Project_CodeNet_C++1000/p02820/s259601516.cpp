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
    int N,K,R,S,P;
    string T;
    cin >> N >> K >> R >> S >> P >> T;
    int point=0;
    REP(i,N){
        if(T[i]=='r'){
            point+=P;
        }else if(T[i]=='s'){
            point+=R;
        }else if(T[i]=='p'){
            point+=S;
        }
        if(i+K<=N){
            if(T[i]==T[i+K]){
                T[i+K]='n';
            }
        }
    };
    cout << point;
    return 0;
}