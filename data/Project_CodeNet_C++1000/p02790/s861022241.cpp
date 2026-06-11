#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;

int main(void){
   ll a,b;
   cin >> a >> b;
   string A,B;
   rep(i,b){
       A+=a+'0';
   }
   rep(i,a){
       B+=b+'0';
   }
   if(a<b){
      cout << A << endl; 
   }
   else{
       cout << B << endl;
   }
   
}
