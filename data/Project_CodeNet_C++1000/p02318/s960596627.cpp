#include<bits/stdc++.h>
#include <bits/stdc++.h>
#define INF 1e9
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
using namespace std;

int main(){
    string s1, s2;
    int xl, yl;
    int dp[1001][1001];
    cin>>s1>>s2;
    xl = s1.size();
    yl = s2.size();
    
    for(int i = 0; i <= xl; i++){
        for(int j = 0; j <= yl; j++){
            dp[i][j] = INF;
        }
    }

    for(int i = 0; i <= yl; i++){
        dp[0][i] = i;
    }
    for(int i = 0; i <= xl; i++){
        dp[i][0] = i;
    }
    for(int i = 0; i < xl; i++){
        for(int j = 0; j < yl; j++){
            dp[i+1][j+1] = min(dp[i][j], min(dp[i+1][j], dp[i][j+1])) + 1;

            if(s1[i] == s2[j]){
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
            }
        }
    }
    cout<<dp[xl][yl]<<endl;
    return 0;
}
