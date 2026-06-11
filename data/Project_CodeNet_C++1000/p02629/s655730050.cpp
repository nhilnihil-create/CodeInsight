#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

int main(){
    ll N; cin >> N;
    string S = "";
    while(N > 0){
        ll rem = N % 26;
        if(rem == 0) rem = 26;
        char ch = rem + 96;
        S += ch;
        N = (N-rem)/26;
    }
    reverse(S.begin(), S.end());
    cout << S << endl;
}