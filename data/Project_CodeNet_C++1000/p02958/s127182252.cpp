#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,ara[52],flag=0;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>ara[i];
    }

    for(int i=1;i<=n;i++)
    {
        if(ara[i]!=i)
        {
            flag++;
        }
    }

    if(flag==0 || flag==2)
    {
        cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;

    return 0;
}
