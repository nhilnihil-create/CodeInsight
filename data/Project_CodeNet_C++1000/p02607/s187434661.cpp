#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,a[1000],count=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i%2==1&&a[i]%2==1)
        {
            count++;
        }
    }
    cout<<count<<'\n';
    return 0;
}