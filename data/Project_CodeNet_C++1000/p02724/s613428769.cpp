#include <bits/stdc++.h>
using namespace std;


int main(void){
   int64_t X;
   cin >> X;
   
   int64_t a,b,ans;
   a=X/500;
   b=(X%500)/5;
   ans=1000*a+5*b;
   
   cout << ans << endl;
   
   

}


