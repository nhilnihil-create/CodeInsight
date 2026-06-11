#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin >> n;
   int mono = n/100;
   int simoni = n%100;
   for(int i=0;i<mono;i++){
       if(simoni >= 5)simoni -= 5;
       else if(simoni == 4)simoni -=4;
       else if(simoni == 3)simoni -=3;
       else if(simoni == 2)simoni -=2;
       else if(simoni == 1)simoni -=1;
       if(simoni == 0){
           cout << 1 << endl;
           return 0;
       }

   }
   cout << 0 << endl;
}
