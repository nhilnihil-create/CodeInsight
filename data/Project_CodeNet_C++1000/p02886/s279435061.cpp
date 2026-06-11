#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,s=0,j,a[100];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            s+=(a[i]*a[j]);
        }
    }
    cout<<s<<endl;
}
