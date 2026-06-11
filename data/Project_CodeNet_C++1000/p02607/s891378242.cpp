#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n,sum=0;cin>>n;
    ll arr[n+5];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(i%2==1&&arr[i]%2==1)
            sum++;
    }
    cout<<sum;

    return 0;
}
