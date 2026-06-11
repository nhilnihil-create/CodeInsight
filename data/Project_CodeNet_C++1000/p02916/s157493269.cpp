#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a[100],b[100],c[100],s=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        cin>>b[i];
    for(i=0;i<n-1;i++)
        cin>>c[i];
    for(i=1;i<n;i++)
    {
        if(a[i]-a[i-1]==1)
            s+=b[a[i]-1]+c[a[i-1]-1];
        else
            s+=b[a[i]-1];
    }
    cout<<s+b[a[0]-1]<<endl;
}
