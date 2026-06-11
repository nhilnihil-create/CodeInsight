#include <bits/stdc++.h>
using namespace std;
 #define MAX 1000000000005
 #define ll long long int
 int main()
 {    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

        long long int m,sum=0,k=0,i,d=MAX,j,sum1=0,sum2=0,sum3=0,l,kk,sum4=0,sum5=0,sum6=0,c=MAX,x,y,q;
         ll n;
           cin>>x>>n;
          ll a[n],b[1000]={0};
           for(i=0;i<n;i++)
             {cin>>a[i];
              b[a[i]]++;
             }
             for(i=x;i>=0;i--)
               {  if(b[i]==0)
                     {  c=i;
                         break;
                     }
               }
               for(i=x+1;i<=1000;i++)
               { if(b[i]==0)
                  { d=i;
                   break;
                  }
               }
               ll e=abs(c-x);
               ll f=abs(d-x);

                if(e<f)
                 cout<<c;
                else if(f<e)
                 cout<<d;
                 else
                    cout<<min(c,d)<<endl;
 }






