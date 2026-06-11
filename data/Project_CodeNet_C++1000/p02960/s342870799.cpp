#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}
const int NM = 1e5+10;
const int MOD = 1e9+7;
int dp[NM][13]; // dp[i][j] : i桁目までで、13で割ってあまりがjになる数の個数

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s; cin>>s;
    int n = s.size();
    reverse(s.begin(), s.end());
    if(s[0]=='?'){
        rep(i, 10) dp[0][i]=1;
    } else {
        int idx = s[0]-'0';
        dp[0][idx]=1;
    }
    int digit = 1;
    for(int i=1; i<n; i++){
        digit *= 10;
        digit %= 13;
        if(s[i]=='?'){
            for(int j=0; j<10; j++){ // ?の候補
                for(int k=0; k<13; k++) { // 前桁でのあまり
                    int idx = (k+j*digit) % 13;
                    dp[i][idx]+=dp[i-1][k];
                    dp[i][idx]%=MOD;
                }
            }
        }else{
            for(int k=0; k<13; k++){ // 前桁でのあまり
                int j = (s[i]-'0');
                int idx = (k+j*digit)%13;
                dp[i][idx] += dp[i-1][k];
                dp[i][idx] %= MOD;
            }
        }
    }
    cout << dp[n-1][5]<<endl;
}