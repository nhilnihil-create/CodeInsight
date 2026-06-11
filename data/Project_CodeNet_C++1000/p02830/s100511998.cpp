#include<iostream>
using namespace std;
int main()
{ 
     int n , j=1, k=0;
     cin>>n;
     char s[n] , t[n] , r[2*n] ;
     for(int i=0 ; i<n; i++)
     { 
          cin>>s[i];
     } 
     for(int i=0 ;i<n;i++)
     { 
         cin>>t[i];
     } 
     for(int i=0 ; i<=n; i++)
      {  
          r[i+k] = s[i];
          r[i+j] =t[i];
          j++;
        k++;
      }
      
     for(int i=0 ; i<2*n; i++)
     { 
          cout<<r[i];
     }
      return 0;
}

     