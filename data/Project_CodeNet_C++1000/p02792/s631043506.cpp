#include <bits/stdc++.h>
#define rep(i, n)for(int i=0,i<(n);++i)
using namespace std;
using ll = long long;

int digit(int n){
    while(n>=10){
         n /= 10;
       }
   return n;
}

int main(){
 int n;
 cin >> n;
 int ans = 0;
 int c[10][10] = {0};
 for(int i= 1;i<=n;i++){
     for(int a = 1; a<=9 ; a++){
        for(int b = 1; b<=9 ; b++){ 
        if(digit(i)==a && i%10 == b) c[a][b] ++;
         }
     }
 }  
 for(int a = 1; a<=9 ; a++){
     for(int b = 1; b<=9 ; b++){ 
         ans += c[a][b]*c[b][a];
     }
}
 cout <<  ans << endl;
 return 0;
}