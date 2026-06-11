#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define reps(i, m, n) for (int i = m; i < n; i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int string_to_int(char a){
    if (a == '1') return 1;
    if (a == '2') return 2;
    if (a == '3') return 3;
    if (a == '4') return 4;
    if (a == '5') return 5;
    if (a == '6') return 6;
    if (a == '7') return 7;
    if (a == '8') return 8;
    if (a == '9') return 9;
    if (a == '0') return 0;
}

int main(void){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int> > dp(n+1, vector<int>(10, n));
  
    repr(i, n-1){
        rep(j, 10) dp[i][j] = dp[i+1][j];
        int num = string_to_int(s[i]);
        dp[i][num] = i;
    }
  
    int ans = 0;
    int judge;
    rep(i, 10)rep(j, 10)rep(k, 10){
        vector<int> key = {i, j, k};
        bool flag = true;
        judge = 0;
        rep(l, 3){
            judge = dp[judge][key[l]];
            if (judge == n) {
                flag = false;
                break;
            }
            judge++;
        }
        if (flag == true) ans++;
    }

    printf("%d", ans);
    return 0;
}

