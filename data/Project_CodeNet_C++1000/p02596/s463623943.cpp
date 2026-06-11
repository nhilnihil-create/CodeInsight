#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k,ans=1;
    cin>>k;
    long long x=7%k;
    for(int i=1;i<=k;i++)
    {
        if(x==0)
        {
            cout<<ans<<endl;
            return 0;
        }
        else
        {
            ans++;
            x=x*10+7;
            x%=k;
        }
    }
    cout<<-1<<endl;
    return 0;
}
