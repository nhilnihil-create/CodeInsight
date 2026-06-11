#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    float x;
    cin>>n;
    float a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    x=a[0]+a[1];
    x=x/2;
    for(i=2;i<n;i++)
    {
        x=(x+a[i])/2;
    }
    cout<<x;


}
