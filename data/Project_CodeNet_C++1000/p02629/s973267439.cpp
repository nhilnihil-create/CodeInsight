#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main (){
    ll N;
    cin >> N;
    string ans;

    while(N > 26){
        int mod = (N - 1) % 26;
        ans = (char)('a' + mod) + ans;
        N = (N - 1) / 26;
    }
    if(N != 0) ans = (char)('a' + N - 1) + ans;
    cout << ans << endl;
}