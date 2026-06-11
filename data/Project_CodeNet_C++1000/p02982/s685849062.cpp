#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d,r;
    cin>>n>>d;
    int a[n][d];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<d;j++)
        {
            cin>>a[i][j];
        }
    }

    int ans=0;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum=0;

            for(int k=0;k<d;k++)
            {
                sum+=pow(a[i][k]-a[j][k],2);
            }

            r=sqrt(sum);

            if(r*r==sum)
            {
                ans++;
            }
        }
    }

    cout<<ans<<endl;
    exit(0);
}
