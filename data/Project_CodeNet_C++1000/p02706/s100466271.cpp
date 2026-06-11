#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[m];
    int sum=0;

    for(int i=0;i<m;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    if(sum>n)
        cout<<-1<<endl;
    else if(sum==n)
        cout<<0<<endl;
    else
        cout<<n-sum<<endl;

    exit(0);
}
