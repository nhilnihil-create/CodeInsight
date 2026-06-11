#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60; //intじゃ扱えないことに注意！
using P = pair<int,int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++) //範囲外参照とループの初期化に注意！

string f(ll n){
    if(n == 0) return "";
    n--;
    return f(n/26) + string(1, 'a' +n%26);
}
int main() {
    ll n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}