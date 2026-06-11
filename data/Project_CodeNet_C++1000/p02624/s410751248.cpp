#include <bits/stdc++.h>
using namespace std;
 #define MAX 1000000000005
 #define ll long long int
 int main()
 {    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        long long int m,sum=0,k=0,i,dd=0,j,sum1=0,x,sum2=0,sum3=0,l,kk,sum4=0,sum5=0,y,z,sum6=0,cc=0;
         ll n;
           cin>>n;
            ll a[n+1],b[n+1]={0};
                 for(i=1;i<=n;i++)
                 {for(j=0;j<=n;j+=i)
                    b[j]++;
                }
                for(i=1;i<=n;i++)
                 sum+=i*b[i];
                 cout<<sum<<endl;
 }


