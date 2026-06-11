#include<iostream>
#include<string.h>
using namespace std;
int  main()
{     int n, sum =1;
       
      cin>>n;
      char c[n];
      for(int i = 0; i<n;i++)
      { 
           cin>>c[i];
      }
      
      for(int j=0 ; j<n-1;j++)
      { 
           
          if(c[j]!=c[j+1])
          { 
               sum++;
          }
          
      }
       cout<<sum;
       return 0;
}

