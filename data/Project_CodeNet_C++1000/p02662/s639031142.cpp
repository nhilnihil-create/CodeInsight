#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<math.h>
#include<map>
#include<unordered_map> 
#include<vector>
#include<queue>
#include<set>
//#include<bits/stdc++.h>
#include<deque> 
#include<bitset>
#include <cmath>
#include<string>
#define N 40
#define K 300005
#define MOD 1e9+7
#define int long long 
#define fastio  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define pi 3.14159265358979323846


int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
int min(int a, int b){
    if(a < b)
        return a;
    return b;
}


int32_t main(){
    fastio
    int n, s;
    cin>>n>>s;
    int po[s + 5];
    int a[n];
    int mod = 998244353;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int dp[n][s + 1];
    for(int i=0;i<n;i++){
        for(int j=0;j<=s; j++){
            dp[i][j] = 0;
            if(j == 0){
                dp[i][0] = 1;
            }
        }
    }
    //cout<<dp[0][0]<<endl;
    dp[0][a[0]] = 1;
    dp[0][0] = 2;
    int ans= 0;
    for(int i=1;i<n;i++){
        for(int j = 0; j<=s; j++){
            dp[i][j] = dp[i-1][j] * 2;
            if(dp[i][j] >= mod){
                dp[i][j] %= mod;
            }
            if(j >= a[i]){
                
                //cout<<"Second "<<i-1<<" "<<j -a[i]<<" "<<dp[i-1][j-a[i]]<<endl;
                dp[i][j] += dp[i-1][j - a[i]];
                if(dp[i][j] >= mod){
                    dp[i][j] %= mod;
                }
            }
            //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }


    }
    cout<<dp[n-1][s]<<endl;


    
    
    



    
  

    




    
   
    
}