#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

int main(){
    ll N; 
    string S; cin >> N >> S;
    ll cnt = 0;
    for(int i = 0; i < N; i++) if(S[i] == 'R') cnt++;
    ll cnt2 = 0;
    for(int i = 0; i < cnt; i++) if(S[i] == 'R') cnt2++;
    cout << cnt - cnt2 << endl;
}
