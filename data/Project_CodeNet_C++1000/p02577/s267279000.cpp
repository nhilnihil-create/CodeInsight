#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

int main(){
    string S; cin >> S;
    ll SUM = 0;
    for(auto ch : S){ SUM += ch - 48; }
    if(SUM % 9 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}