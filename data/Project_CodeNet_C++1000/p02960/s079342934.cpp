// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<ll>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int main(){
    string S;
    cin >> S;
    int N = S.size();
    S += ' ';
    reverse(all(S));
    Graph dp(13, vector<ll>(N + 1, 0));
    dp[0][0] = 1;

    int dig = 1;
    for(int i = 1; i <= N; i++){
        if(S[i] == '?'){
            for(int j = 0; j < 10; j++){
                int tmp = j * dig % 13;
                for(int k = 0; k < 13; k++){
                    dp[(k + tmp) % 13][i] += dp[k][i - 1];
                    dp[(k + tmp) % 13][i] %= INF;
                }
            }
        }
        else {
            for(int k = 0; k < 13; k++){
                int j = (S[i] - '0');
                int tmp = j * dig % 13;
                dp[(k + tmp) % 13][i] += dp[k][i - 1];
                dp[(k + tmp) % 13][i] %= INF;
            }
        }

        dig *= 10;
        dig %= 13;
    }

    cout << dp[5][N] << endl;
}