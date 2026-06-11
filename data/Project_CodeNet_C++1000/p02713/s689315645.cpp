#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int dp[201][201] ;
int gcd1(int a, int b) 
{ 
    if(dp[a][b] == -1){
        if(a == 0){
            dp[0][b] = b;
            return b;
        }else{
            int ans = gcd1(b%a, a);
            dp[a][b] =  ans;
            dp[b][a] = ans;
            return ans;
        }
    }
    return dp[a][b];
} 
int gcd(int a, int b , vector <vector<int>> &dp) 
{   if(dp[a][b] == -1){
        if (a == 0) dp[a][b] = b; 
         
        dp[a][b] =  gcd(b % a, a , dp); 
        dp[b][a] = dp[a][b];
        return dp[a][b];
    }
    return dp[a][b];
    
} 
int main() {
    int n;
    cin >> n;
    long long sum = 0;
    memset(dp , -1 , sizeof(dp));

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= n ; j++){
            for(int k = 1; k <= n ; k++){
                sum += gcd1(i , gcd1(j , k ) );
            }
        }
    }
    cout << sum << endl;
}
