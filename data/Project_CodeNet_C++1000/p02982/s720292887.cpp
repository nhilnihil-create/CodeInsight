#include <iostream> 
#include<algorithm>
using namespace std;

 int main()
 {
   int i,j,k,ans=0,sum,num,count=0,c,e=0;
   
   int n,d,x[10][10];
   cin>>n>>d;
   for(i=0;i<n;i++)
   {
     for(j=0;j<d;j++)
     {
     cin>>x[i][j];
     }
   }
   for(i=0;i<n-1;i++)
   {
     
     for(j=i+1;j<n;j++)
     { 
       //cout<<"I,J="<<i<<" "<<j<<endl;
       e=0;
       for(k=0;k<d;k++)
       {
         c=x[j][k]-x[i][k];
         c*=c;
         e+=c;
       }
      // cout<<"e="<<e<<endl;
   
       k=1;
       
       while(1)
       {
         if(k*k==e)
         {
           count++;
          // cout<<"ans"<<endl;
           break;
         }
         if(k*k>e)break;
         k++;
       } 
       
     }
   }
   cout<<count<<endl;
 }