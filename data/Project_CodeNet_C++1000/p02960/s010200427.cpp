#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using ll = long long;
using ld = long double;
using namespace std;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main(){
    FIN;

    string s; cin >> s;
    vector<vector<ll>> dp(s.size()+1,vector<ll>(13,0));
    dp[0][0] = 1;
    for(ll i=0;i<s.size();i++){
        for(ll j=0;j<13;j++){
            if(s[i] == '?'){
                for(ll k=0;k<10;k++){
                    dp[i+1][(j*10+k)%13] += dp[i][j];
                    dp[i+1][(j*10+k)%13] %= mod;
                }
            }else{
                int k = s[i]-'0';
                dp[i+1][(j*10+k)%13] += dp[i][j];
                dp[i+1][(j*10+k)%13] %= mod;
            }
        }
    }

    cout << dp[s.size()][5] << endl;
    return 0;
}