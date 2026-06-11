#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; i++)
static const long long INF = 1000000;
using p = pair<int64_t,int64_t>;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;}

int main(){
    string s;
    cin >> s;
    int l = s.length();
    vector<int> vec(l);
    rep(i,l){
        int x = s[i] - '0';
        vec[i] = x;
    }
    reverse(vec.begin(),vec.end());
    //動的計画法。下n-1桁までのみを考えたときの使った紙幣の最小値。次の位から繰り下がりが発生するのかによって場合分け。
    //繰り上がりが発生した場合、次の桁に影響が出る。
    //最後一桁の処理をどうするのか。
    vector <vector<int>> dp(l,vector<int>(2,0));
    dp[0][0] = vec[0];
    dp[0][1] = 10 - vec[0];
    for (int i = 1; i < l; i++){
        dp[i][0] = min(dp[i-1][0] + vec[i],dp[i-1][1] + vec[i] +1);
        dp[i][1] = min(dp[i-1][0] + 10 - vec[i],dp[i-1][1] + 9 - vec[i]);
        
    }
    dp[l-1][1]++;
    int64_t x = min(dp[l-1][0], dp[l-1][1]);
    cout << x << endl;

}