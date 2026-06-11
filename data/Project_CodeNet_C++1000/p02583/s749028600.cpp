
#include <bits/stdc++.h>

using namespace std;

int main()
{   
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int count=0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            if(a[i]!=a[j])
            {
                for(int k=j+1;k<n;k++)
                {
                    if(a[k]<(a[j]+a[i])&&a[j]!=a[k]) count++;
                }
            }
        }
    }
    cout<<count;
    return 0;
}
