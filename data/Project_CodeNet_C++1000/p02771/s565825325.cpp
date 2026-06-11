#include <bits/stdc++.h>

using namespace std;

int main()
{
     int A,B,C;
     cin>>A>>B>>C;
    if(A>=1&&A<10&&B>=1&&B<10&&C>=1&&C<10){
     if((A==B&&A!=C&&B!=C)||(B==C&&B!=A&&C!=A)||(A==C&&A!=B&&C!=B)){
         cout<<"Yes";
     }
     else{
         cout<<"No";
     }
    }
   return 0;
}