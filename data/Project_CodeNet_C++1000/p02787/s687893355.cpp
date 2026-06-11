#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
    int h,n;cin >> h >> n;
    vector<P> magic(n);
    vector<int> dp(h+1,INF);
    rep(i,n){
        int a,b;cin >> a >> b;
        magic[i] = make_pair(a,b);
    } 
    dp[0]=0;
    for(int i = 1;i<=h;i++){
        for(auto p:magic){
            dp[i] = min(dp[i],dp[max(0,i-p.first)]+p.second);
        }
    }
    cout << dp[h] << endl;
 }