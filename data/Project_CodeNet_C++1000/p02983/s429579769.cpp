#include <bits/stdc++.h>
using namespace std;
int main(){
   long a,b;
   cin >> a >> b;
   if(b-a+1 >= 2300)cout << 0 << endl;
   else{
       long min = 3000;
       for(long i=a;i<b;i++){
           for(long j=i+1;j<b+1;j++){
               long x = i%2019, y = j%2019;
               if((x*y)%2019 < min)min = x*y%2019;
           }
       }
       cout << min << endl;
   }
}