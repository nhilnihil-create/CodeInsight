#include <stdio.h>
#include <math.h>
#include<bits/stdc++.h>
using namespace std;
#define int long long int
 #define hi ios_base :: sync_with_stdio(false); cin.tie(0);cout.tie(0);
int i,j,k,mo;
main()

{
    int n;cin>>n;
    int a[n+1],b[n+1];
    for(i=0;i<n+1;i++) cin>>a[i];
    for(i=0;i<n;i++) cin>>b[i];
    b[n]=0;
    int s=0,cm=0;
    for(i=0;i<n+1;i++)
    {
        if(i==0&&b[i]>=a[i])
        {
            s=a[i];
            cm+=a[i];
            a[i]=a[i]-s;
            b[i]=b[i]-s;
        }
        else if(i==0&&a[i]>b[i])
        {
            cm+=b[i];
            s=b[i];
            a[i]=a[i]-s;
            b[i]=b[i]-s;
        }
        else
        {
            int k=b[i-1];
            if(a[i]>=k)
            {
                a[i]=a[i]-k;
                cm=cm+k;
                if(a[i])
                {
                    if(a[i]>=b[i])
                    {
                        s=b[i];
                        a[i]=a[i]-s;
                        b[i]=b[i]-s;
                        cm+=s;
                    }
                    else
                    {
                        s=a[i];
                        a[i]=a[i]-s;
                        b[i]=b[i]-s;
                        cm+=s;
                    }
                }
            }
            else
            {
                cm+=a[i];

                a[i]=a[i]-k;

            }
        }
    }
  cout<<cm<<endl;

}
