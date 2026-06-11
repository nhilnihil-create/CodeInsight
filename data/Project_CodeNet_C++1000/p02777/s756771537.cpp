#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++);
#define FOR(i, m, n) for(int i = m; i < n; i++);
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;

int main(){
    string s, t, u;
    int a, b;
    cin >> s >> t >> a >> b >> u;
    if(s == u){
        cout << a-1 << " " << b;
    }else {
        cout << a << " " << b-1;
    }
    return 0;
}
