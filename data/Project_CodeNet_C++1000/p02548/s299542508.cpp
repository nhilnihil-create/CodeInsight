#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n;
typedef long long ll;
ll ans=0;
int main()
{
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        ans+=(n-1)/i;
    }
    cout<<ans<<endl;
}
