#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int n,k,i,h,y;
    cin >> n;
    y=1000000000000;
  
   for(i=1;i*i<=n;i++)
     {
        if((n%i)==0)
            {
                k=n/i;
           y=min(y,k+i);
            }
              
     }
    
     h=y-2;
     cout << h;
     
     
     
        return 0;
        
}