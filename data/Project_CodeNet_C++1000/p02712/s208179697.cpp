#include <bits/stdc++.h>
 #define rep(i,n) for(int i=1;i<=n;i++)
 using namespace std;
  int main(){
    long long a;
     cin >> a;
     long long ans=0;
     rep(i,a){
         if(i%3!=0 && i%5!=0){
             ans+=i;
         }
     }
     cout << ans << endl;
  }