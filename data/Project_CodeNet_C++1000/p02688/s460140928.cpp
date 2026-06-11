#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;cin>>n>>k;
    int a[n];
    for(int i=1;i<=n;i++)a[i]=0;

    while(k--)
    {
        int d;cin>>d;
        for(int i=0;i<d;i++)
        {
            int x;cin>>x;
            a[x]=1;
        }
    }

    int cnt=0;
    for(int i=1;i<=n;i++)if(a[i]==0)cnt++;
    cout<<cnt<<endl;
}
