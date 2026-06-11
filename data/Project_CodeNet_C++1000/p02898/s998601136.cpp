#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{

    int i,n,k,c=0;
    cin>>n>>k;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        if(a[i]>=k)
            c++;
    }
    cout<<c;
    return 0;
}
