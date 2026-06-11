#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
 int a,b,c,d;
 cin >> a >> b >> c >> d;
 while(true){
   c -= b;
   if(c<=0){
     cout << "Yes" << endl;
     return 0;
   }
   a -= d;
   if(a<=0){
     cout << "No" << endl;
     return 0;
   }
 }
}
  
    
