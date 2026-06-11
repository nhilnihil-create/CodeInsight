#include <bits/stdc++.h>

using namespace std;

#define mod 1e9+7

int main()

{

    int n,k;

    cin>>n>>k;

    int a[n+1],b[n+1];

    for(int i=1; i<=n; i++)

    {

        cin>>a[i];

    }

    while(k--)

    {

        memset(b,0,sizeof(b));

       for(int i=1;i<=n;i++)

       {

         if(a[i]+i<n)

         {

             b[i]++;

             b[i+a[i]+1]--;

         }

         else

         {

             b[i]++;

         }

         if(i-a[i]>=1)

         {

             b[i-a[i]]++;

             b[i]--;

         }

         else

         {

             b[1]++;

             b[i]--;

         }

       }

       a[1]=b[1];

       for(int i=2;i<=n;i++)

       {

           a[i]=a[i-1]+b[i];

       }

       int flag=0;

       for(int i=1;i<=n;i++)

       {

           if(a[i]!=n)

           {

               flag++;

               break;

           }

       }

       if(!flag)

       {

           break;

       }

    }

    for(int i=1; i<=n; i++)

    {

        cout<<a[i]<<" ";

    }

    return 0;

}