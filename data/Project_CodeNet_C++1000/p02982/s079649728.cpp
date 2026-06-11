#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d,b;
    cin>>n>>d;
    int a[n][d];
    for(int i=0; i<n; i++)
    for(int j=0; j<d; j++)
    cin>>a[i][j];
    int ans=0;
    for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++)
    {
        int sum=0;
        for(int k=0; k<d; k++)
        sum+=pow(a[i][k]-a[j][k],2);
        b=sqrt(sum);
        if(b*b==sum)
            ans++;
    }
    cout<<ans<<endl;
}
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d,a;
    cin>>n>>d;
    int x[n][d];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<d; j++)
        {
            cin>>x[i][j];
        }
    }
    int ans=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int sum=0;
            for(int k=0; k<d; k++)
            {
                sum+=pow(x[i][k]-x[j][k],2);
            }
            a=sqrt(sum);
            if(a*a==sum)
                ans++;
        }
    }
    cout<<ans<<endl;
}
*/
