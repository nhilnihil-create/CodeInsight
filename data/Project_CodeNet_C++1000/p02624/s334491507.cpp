#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
    int n;
    cin >> n;
    unsigned long long ans = 0;
    for(int i = 1; i <= n; ++i){
        ll N = n / i;
        ll cnt = (N * (2 * i + (N - 1) * i)) / 2;
        ans += cnt;
    }
    cout << ans << endl;
    return 0;
}