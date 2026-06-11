#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[100],b[100],c=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            c++;
        }
    }
    if(c==0 || c==2)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
