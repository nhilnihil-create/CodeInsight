#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

string s;
vector<int> v;
long long dp[N][2];
void f (){
    dp[0][1] = 1;
    for (int i = 0; i < v.size() - 1; ++i){
        for (int nxt = 0; nxt <= 1; ++nxt){
            for (int nxt1 = 0; nxt1 <= 1; ++nxt1){
                for (int j = 0; j <= 1; ++j){
                    if (nxt && nxt1) continue;
                    if (j && (nxt + nxt1) > v[i + 1]) break;
                    dp[i + 1][(j & (nxt + nxt1 == v[i + 1]))] += dp[i][j];
                    dp[i + 1][(j & (nxt + nxt1 == v[i + 1]))] %= mod;
                }
            }
        }
    }
    cout << (dp[(int)v.size() - 1][1] + dp[(int)v.size() - 1][0]) % mod << '\n';
}
int main(){


    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    v.push_back(0);
    for (int i = 0; i < s.size(); ++i) v.push_back(s[i] - '0');
    f ();

}
