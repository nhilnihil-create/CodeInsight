#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const int MOD = 1000000007;
ll cnt =0,ans=0;

int main(){
   int k;   cin >> k;
   

   ll v=7;
   for(int i=1;i<1000000;i++){
       if(v%k == 0){
           cout << i << endl;
           return 0;
       }

       else{
           v*=10;
           v+=7;
           v=v%k;
           
       } 
   }

   cout << -1 << endl;
}