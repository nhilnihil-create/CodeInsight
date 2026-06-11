#include<bits/stdc++.h>
#define int long long 
using namespace std;
int col[1000];
main()
{
    int n;
    cin>>n;
    for(int i=1;i<=20;i++)
    {
        int st=(1<<i);
        while(st<n)
        {
            col[st]=i;
            st+=(1<<i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            cout<<col[j-i]+1<<" ";
        }
        cout<<'\n';
    }
}
