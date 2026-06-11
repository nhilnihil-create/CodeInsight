#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,i,a[1000],s=0,c=0;
    cin>>n>>x;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=1;i<=n+1;i++)
    {
        if(s<=x)
            c++;
        s+=a[i-1];
    }
    cout<<c<<endl;
}
