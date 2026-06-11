#include<bits/stdc++.h>
using namespace std;
long long l[101];
long long n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>l[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int z=j+1;z<=n;z++)
            {
                if(l[i]!=l[j] && l[j]!=l[z] && l[i]!=l[z])
                    if(l[i]+l[j]>l[z] && l[i]+l[z]>l[j] && l[j]+l[z]>l[i])
                       ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
