//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
  #define MOD 1000000007
   
   long long int power(long long int x,long long int n){
       long long int res = 1;
       while(n!=0){
           if(n%2 == 1){
               res =( (res % MOD) * (x % MOD) )% MOD;
               n--;
           }else if(n%2 == 0){
               x = ((x % MOD) * (x % MOD)) % MOD;
               n = n/2;
           }
       }
          return res;
   }
int main(){
    
    long long int n,i,j;
    
    cin >> n;
    
    if(n<=1) cout << 0 << endl;
    else{
        cout << (((((((power(10,n) - power(9,n))% MOD + MOD) % MOD) - power(9,n)) % MOD + MOD)%MOD) + (power(8,n) % MOD))%MOD << endl;
    }
    return 0;
}
