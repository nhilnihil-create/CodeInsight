#include <bits/stdc++.h>
using namespace std;
int main(){
    long x,y;
    long a; cin >> a;
   for(int i=sqrt(a);i>=1;i--){
       if(a%i == 0){
           x = i,y = a/i;
           break;
       }
   }
   cout << x+y-2 << endl;
}
