#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,c=0,ans=0;
    cin>>n;
    int a[n]={};
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        if(a[i]<=a[i-1])
            ++c;
        else
            c=0;
        ans=max(ans,c);
    }
    cout<<ans;
    return 0;
}

