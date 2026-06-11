#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;
int main(){
    ll N, ans = 0;
    cin >> N;
    for (ll i = 1; i <= N - 1; i++)
    {
        ans += (N - 1) / i;
    }
    cout << ans << endl;
}
