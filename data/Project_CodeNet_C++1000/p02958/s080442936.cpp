#include <iostream> 
#include<algorithm>
using namespace std;

 int main()
 {
  int n,a[50],b[50],i,j,k,f,m;
  cin>>n;
   for(i=0;i<n;i++)
   {
     cin>>a[i];
   }
   f=0;
   for(i=0;i<n-1;i++){if(a[i]>a[i+1])f=1;}
   if(f==0){cout<<"YES"<<endl;return 0;}
   for(i=0;i<n;i++)
   {
     
     for(j=0;j<n;j++)
     {
       for(k=0;k<n;k++){b[k]=a[k];}
       m=b[i];
       b[i]=b[j];
       b[j]=m;
       f=0;
       for(k=0;k<n-1;k++){if(b[k]>b[k+1]){f=1;break;}}
       if(f==0){cout<<"YES"<<endl;return 0;}
     }
   }
   cout<<"NO"<<endl;
 }