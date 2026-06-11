#include<bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
    int n,i,j;
    cin>>n;
    int sum=(n*(n+1))/2;
    for(i=2;i<=n;i++)
    {
        for(j=i;j<=n;j+=i) sum+=(j);
    }
    cout<<sum;
}
