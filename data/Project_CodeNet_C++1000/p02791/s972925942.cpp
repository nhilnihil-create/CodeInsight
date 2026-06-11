#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
        cin>>a[i];
    int d=a[0];
    int s=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]<=d)
            ++s;
        d=min(d,a[i]);
        if(a[i]==1)
            break;
    }
    cout<<s<<endl;
    return 0;
}
