#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

int main(){
    string S; cin >> S;
    ll cnt = 0;
    for(int i = 0; i < S.size(); i++) if(S[i] == 'R') cnt++;
    if(cnt == 1) cout << 1 << endl;
    else if(cnt == 2){
        if(S[1] == 'R') cout << 2 << endl;
        else cout << 1 << endl;
    }
    else if(cnt == 3) cout << 3 << endl;
    else cout << 0 << endl;
}