#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,n,i,ans,cnt,j,k,x,p=0,q=0;
       cin>>x>>n;
       int a[n];
       for(i=0;i<n;i++)
       {
           cin>>a[i];
       }
       i=x;
       j=x;
       while(i<101,j>=0)
        {
            p=0;
            q=0;
       for(k=0;k<n;k++)
       {

           if(a[k]!=j){
            p++;
       }

           if(a[k]!=i){
            q++;
           }
       }
        if(p==n)
       {
           cout<<j<<endl;
           break;
       }
       if(q==n)
           {
               cout<<i<<endl;
               break;
           }
       i++;
       j--;
        }

}
