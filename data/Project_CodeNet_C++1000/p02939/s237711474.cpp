#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}

int main(){
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(2)); //dp[i][j]...i番目の文字列を長さj+1でとったときの最大
    dp[0][0] = 1;
    int ans = 0;
    for(int i = 1; i < n; i++){ 
        //今回は長さ2までしかとらない
        if(s[i-1] != s[i]){
            chmax(dp[i][0], dp[i-1][0]+1); // i-2|i-1|i
        }
        chmax(dp[i][0], dp[i-1][1]+1); // i-2 i-1|i
        if(i >= 2){
            chmax(dp[i][1], dp[i-2][0]+1); // i-2|i-1 i
            chmax( dp[i][1], dp[i-2][1]+1); // i-3 i-2 | i-1 i
        }
    }

    ans = max(dp[n-1][0], dp[n-1][1]);
    cout << ans << endl;
    return 0;
}
