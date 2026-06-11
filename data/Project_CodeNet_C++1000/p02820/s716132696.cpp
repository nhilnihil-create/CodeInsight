#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
long long inf = pow(10, 9);

int n, k, r, s, p;
string t;
int dp[100000 + 1], res = 0;
int main(){
    cin >> n >> k >> r >> s >> p >> t;
    map<char, int> score;
    score['r'] = p;
    score['s'] = r;
    score['p'] = s;
    rep(i, n){
        if(i < k){
            dp[i] = 1;
            res += score[t[i]];
        }
        else if(t[i - k] == t[i]){
            if(dp[i - k] == 0){
                dp[i] = 1;
                res += score[t[i]];
            }
        }
        else{
            dp[i] = 1;
            res += score[t[i]];
        }
    }
    cout << res << endl;
}