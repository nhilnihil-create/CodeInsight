#include<iostream>
using namespace std;
int main()
{ 
     int d[100] , n, sum =0;
     cin>>n;
     for(int i=0 ; i<n;i++)
     { 
          cin>>d[i];
     } 
    for(int i=0 ; i<n-1;i++)
    { 
         for(int j=i+1 ; j<n;j++)
         
          sum  =  sum +(d[i]*d[j]);
    }
    cout<<sum;
return 0;
} 
