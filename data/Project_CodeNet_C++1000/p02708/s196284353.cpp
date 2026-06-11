#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1000000007;
int main(){
   int n , k;
   cin>>n>>k;
   int arr[n+1];
   for(int i = 0 ; i <= n; i++){
   		arr[i] = i;
   }
   ll sum = 0;
   int x = 0;
   int y = 0;
   for(int i = 0 ; i < k ; i++){
   	      sum += arr[i];
   }
   ll sum2 = 0;
   for(int i = n ; i > n-k ; i--){
   	       sum2 += arr[i];
   }
   x = k;
   y = n-k;
   ll ans = 0;
   ans = sum2 - sum+1;
   while( x <= n && y >= 0){
   	     sum += arr[x];
   	     sum2 += arr[y];
   	     ans = (ans%mod + (sum2 - sum+1 + mod)%mod + mod)%mod;
   	     x++;
   	     y--;
   }
   cout<<ans<<endl;
}