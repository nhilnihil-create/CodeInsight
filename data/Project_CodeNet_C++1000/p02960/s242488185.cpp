#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define F first
#define S second
#define mod 1000000007
#define pb push_back
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int NUM = 2e5 + 5;

int main(){
    ios
    int num_tests=1; 
    //cin>>num_tests;
    while(num_tests-->0){
        string s; cin>>s;
        int n = s.size();
        ll dp[n+1][13];
        for(int i=0;i<=n;i++)
            for(int j=0;j<13;j++)
                dp[i][j]=0;
        dp[0][0]=1; 
        // dp[i][j] is the number of ways to create i-th digit having modulo j%13
        for(int i=0;i<n;i++){
            for(int j=0;j<10;j++){
                // j is the no of choices if s[i]=='?'
                int next = s[i]-'0'; // otherwise we will go with the given value
                if(s[i]=='?') next = j;
                for(int k=0;k<13;k++){
                    // dp[i][k] => remainder is k
                    // so if we append j next to i-th digit then the remainder will be (10*k+j)%13
                    int rem = (10*k + next)%13;
                    dp[i+1][rem] += dp[i][k];
                    dp[i+1][rem] = dp[i+1][rem]%mod;
                }
                if(s[i]!='?') break;
            }
        }
        cout<<dp[n][5];
    }   
}
