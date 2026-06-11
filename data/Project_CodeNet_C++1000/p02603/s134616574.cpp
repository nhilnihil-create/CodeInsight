#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
   cin>>a[i];
   ll stock=0;
   ll yen=1000;
  int i=0;
       while(i<n)
       {
           while(i+1<n&&a[i]>=a[i+1])
           {
               i++;
               
           }
           if(i<n)
           {
           stock+=yen/a[i];
           yen=yen%a[i];
           }
           
           while(i+1<n&&a[i]<=a[i+1])
           {
               i++;
              
           }
           if(i<n)
           {
           yen+=stock*a[i];
           stock=0;
           }
           if(i==n-1)
           break;
       }
       if(yen>1000)
   cout<<yen;
   else
   cout<<"1000";
   return 0;
}