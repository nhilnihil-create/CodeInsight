#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,y=0,no=0;
    bool isPrime = true;
    cin>> n;
    if (n >= 1 && n <= 9) cout<< "Yes";
    if(n>9){
        for (i = 2; i <= n / 2; ++i) {
      if (n % i == 0) {
         isPrime = false;
         break;
      }
   }
   if (isPrime)
      cout << "No";
   else{
    for(i=2; i<=9; i++){
        if(n%i==0){
         int c= n/i;
        if(c<=9){
            //cout << "Yes";
            y++;

        }
        else {
                //cout << "No";
                no++;
        }
        }
   }
   if(y>=1) cout << "Yes";
   else cout << "No";
   }

   return 0;
    }
}