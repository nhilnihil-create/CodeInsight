#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main (){
    ll N;
    cin >> N;
    string ans;
    while(N > 26){
        int mod = N % 26;
        if(mod != 0){
            ans = (char)('a' + mod - 1) + ans;
            N = N / 26;
        }else{
            ans = 'z' + ans;
            N = N / 26 - 1;
        }
    }
    if(N != 0) ans = (char)('a' + N - 1) + ans;
    cout << ans << endl;
}