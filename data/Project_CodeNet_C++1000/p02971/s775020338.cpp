#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n]={},m1=-1,m2=-1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>m1)
        {
            m2=m1;
            m1=a[i];
            continue;
        }
        if(a[i]>=m2)
            m2=a[i];

    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==m1)
            cout<<m2;
        else
            cout<<m1;
        cout<<'\n';
    }

    return 0;
}

