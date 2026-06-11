#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

int main(){
    string S, T; cin >> S >> T;
    ll ans = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] != T[i]) ans++;
    }
    cout << ans << endl;
}