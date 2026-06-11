#include<bits/stdc++.h>
using namespace std;
#define N 250
#define ll long long
#define int ll
#define pb push_back
#define pi pair<ll , ll>
#define mp make_pair
#define mod 1000000007
int32_t main(){
int n;
cin>>n;
int arr[n];
for(int i = 0 ; i < n ;i++){
    cin>>arr[i];
}
int prev[n+1] = {0};
int dp[n+1] ;
for(int i = 0 ; i <= n ; i++){
    dp[i] = -1;
}
int freq[n+1] = {0};
int zero = 3;
int ans = 1;
for(int i = 0 ; i < n ;i++){
       freq[arr[i]]++;
      if(arr[i] == 0){
          if(zero == 0){
              cout<<0<<endl;
              return 0;
          }
            ans = ((ans%mod)*(zero%mod) + mod)%mod;
            zero--;
      }
      else{
              int between = freq[arr[i]-1]-prev[arr[i]-1];
              if(dp[arr[i]] == -1){
                    if(between == 0){
                        cout<<"0"<<endl;
                        return 0;
                    }
                   ans = ((ans%mod)*(between%mod) + mod)%mod;
                  dp[arr[i]] = freq[arr[i]-1]-1;
              }
              else{
                   if(between + dp[arr[i]] <= 0){
                       cout<<"0"<<endl;
                       return 0;
                   }
                 ans = ((ans%mod)*((between + dp[arr[i]])%mod) +mod)%mod;
                 dp[arr[i]] = dp[arr[i]] + between-1;
              }
             prev[arr[i]-1] = freq[arr[i]-1];
      }
}
cout<<(ans+mod)%mod<<endl;
    
}
