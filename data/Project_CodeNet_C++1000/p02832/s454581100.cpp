#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ar[n+1];
    for(int i=1;i<=n;i++)
        cin>>ar[i];
    int cnt=0,j=1;
    for(int i=1;i<=n;i++)
    {
        if(ar[i]==j)
        {
            cnt++;
            j++;
        }
    }
    if(n-j+1==n)
        cout<<-1<<endl;
    else
        cout<<n-j+1<<endl;
    return 0;
}
