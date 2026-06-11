#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod =1e9+7;
ll boom[4];
int main()
{
    int n,a;cin>>n;
    ll ans=1;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        int sum=0;
        for(int j=0;j<3;j++)
        {
            if(boom[j]==a) sum++;
        }
        ans=ans*sum%mod;
        for(int j=0;j<3;j++)
        {
            if(boom[j]==a)
            {
                boom[j]++;
                break;
            }
        }
    }
    cout<<ans<<endl;
}
