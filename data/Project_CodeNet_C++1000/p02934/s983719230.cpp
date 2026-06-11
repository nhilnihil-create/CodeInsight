#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    double a[1000],s=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        s+=(1/a[i]);
    cout<<1/s<<endl;
}
