#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[10000],i,j,n,c=0,b[100000];
    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+n);


    for(i=0;i<n;i++)
    {
        if(a[i]==b[i]) c++;
    }

    if(n-c==2 || c==n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
