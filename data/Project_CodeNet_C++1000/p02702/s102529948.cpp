/*
 * welcome to my code!
 * ----------------------------------------
 * author : lynmisakura
 */
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i,n) for(int i = 0;i < n;i++)

template<class T> bool chmin(T& a,T b){ if(a > b){ a = b; return true; } return false; }
template<class T> bool chmax(T& a,T b){ if(a < b){ a = b; return true; } return false; }

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;cin >> s;

    int64_t tens = 1;
    int64_t tmp = 0;

    const int64_t MOD = 2019;

    map<int64_t ,int64_t > M;
    M[0]++;
    int64_t ans = 0;

    for(int i = int(s.size()) - 1;i >= 0;i--){
        tmp = (tmp + (tens * (s[i] - '0')) % MOD) % MOD;
        tens = (tens * 10) % MOD;
        ans += M[tmp];
        M[tmp]++;
    }

    cout << ans << '\n';
}

