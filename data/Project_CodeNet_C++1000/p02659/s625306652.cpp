#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60; //intじゃ扱えないことに注意！
using P = pair<int,int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++) //範囲外参照とループの初期化に注意！

int main() {
    ll a;
    double b;
    cin >> a >> b;
    ll ib = b*100+0.5; //小数はなるべく整数で扱う。
    a *= ib; //+0.5は切り捨て対策。
    a /= 100;
    cout << a << endl;
    return 0;
}