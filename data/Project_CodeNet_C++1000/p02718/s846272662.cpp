#include<bits/stdc++.h>
#include<math.h>
const double PI = acos(-1);
using namespace std;
int main()
{

     long int t,i,b,n;
     
     double m,p,k,l; 
    cin>>n>>m;
    long int a[n];
     for(i=0;i<n;i++)
     cin>>a[i];
     b=0;
     k=0;
     for(i=0;i<n;i++)
     {
     k=k+a[i];
         
     }
     for(i=0;i<n;i++)
     {
         if(a[i]>=(k/(4*m)))
           b++;
     }
    if(b>=m)
    cout<<"Yes";
    else
    cout<<"No";
    
}