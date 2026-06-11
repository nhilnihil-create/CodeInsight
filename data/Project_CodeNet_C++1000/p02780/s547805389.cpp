#include <bits/stdc++.h>
using namespace std;

int s[1010];
int p[200010];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++)cin>>p[i];

    for(int i=1;i<=1000;i++)s[i]=i+s[i-1];

    int sum=0;
    for(int i=0;i<k;i++)sum+=p[i];

    int m=sum;
    int mpos=0;

    for(int i=1;i<n-k+1;i++)
    {
        sum=sum-p[i-1]+p[i+k-1];
        if(sum>m){m=sum;mpos=i;}
    }

    double ans=0.0;

    for(int i=0;i<k;i++)
    {
        double q=s[p[i+mpos]];
        double qq=p[i+mpos];
        ans+=q/qq;
    }

    printf("%.10lf",ans);

    return 0;
}
