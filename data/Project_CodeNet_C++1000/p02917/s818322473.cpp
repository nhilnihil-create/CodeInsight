#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,sum=0;
    cin>>n;
    int a[n]={};
    for(int i=0;i<n-1;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n-1;i++)
        sum+=min(a[i],a[i-1]);
    sum+=a[0]+a[n-2];
    cout<<sum;
}


