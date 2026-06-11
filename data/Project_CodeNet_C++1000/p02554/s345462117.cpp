#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a = 1, b = 1, c = 1;
    int N; cin >> N;
    for(int i = 0; i < N; ++i){
        a *= 10;
        a %= INF;
        b *= 8;
        b %= INF;
        c *= 9;
        c %= INF;
    }
    ll ret = a - 2*c + b;
    ret %= INF;
    ret = (ret+INF)%INF;
    cout << ret << '\n';
    return 0;
}