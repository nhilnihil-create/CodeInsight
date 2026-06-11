#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
   int n,m;
   cin >> n >> m;
   vector<int> oks(n + 1,true);
   for(int i = 0;i < m;i++){
         int a;
         cin >> a;
         oks[a] = false;
   }
   
   vector<long long int> dp(n + 1);
   dp[0] = 1;
   for(int i = 0;i < n;i++){
         for(int j = i + 1;j <= min(n,i + 2);j++){
               if(oks[j]){
                     dp[j] += dp[i];
                     dp[j] %= long(1e9 + 7);
               }
         }
   }
   cout << dp[n] << endl;
}
