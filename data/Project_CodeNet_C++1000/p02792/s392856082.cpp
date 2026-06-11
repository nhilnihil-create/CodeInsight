#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int digit(long long q)
{
        int  f1,d1;
   d1=((int)(log10(q)));
   f1=(int) (q/(int)(pow(10,d1)));
   return f1;
}
int main()
{
    long long q,i,j,k=0,p;
    cin>>q;
    int a[10][10]={0};
    for(i=1;i<=q;i++)
    {
         if(i%10==0)continue;
         else
         {
             j=digit(i);
             a[j][i%10]++;
         }
    }
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        {
           k+=a[i][j]*a[j][i];
        }

    }
    cout<<k<<endl;
    return 0;
}
