#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

int main(){
    ll L, R, D, cnt = 0; cin >> L >> R >> D;
    for(;L <= R; L++) if(L%D==0)cnt++;
    cout << cnt << endl;

} 