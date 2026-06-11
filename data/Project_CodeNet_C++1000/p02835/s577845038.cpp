#include<iostream>
using namespace std;
int main()
{ 
     int   a1,a2,a3,sum;
     
     cin>>a1;
     cin>>a2;
     cin>>a3;
     
     sum = a1 + a2 + a3;
     if(sum>=22)
     { 
          cout<<"bust";
     }
     else 
     {
         cout<<"win";
     }
      return 0;
} 
