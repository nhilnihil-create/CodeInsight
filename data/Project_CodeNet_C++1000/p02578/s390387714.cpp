#include <bits/stdc++.h>
using namespace std ;
int main()
{
    int x;
    cin>>x;
    long long a[x];
    long long s=0;
    for(int i=0;i<x;i++)
        {
        cin>>a[i];
        if(i>0&&a[i-1]>a[i])
            {
        s =s+a[i-1]-a[i];
        a[i]=a[i-1];
}
    }
    cout<<s;
    return 0 ;
    }
