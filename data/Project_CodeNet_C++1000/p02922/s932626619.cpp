#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,sum=1,ans=0;
    cin>>a>>b;
    while(sum<b)
    {
        sum=sum-1+a;
        ans++;
    }
    cout<<ans;
}