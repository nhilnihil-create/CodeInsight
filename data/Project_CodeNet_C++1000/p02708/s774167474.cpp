#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,k;
    cin >> n >> k;
    long long int ans=0;
    long long int m=1000000007;
    for(long long int i=k;i<=n;i++)
    {
        ans+= (((n*(n+1))/2) -(((n-i)*(n-i+1))/2)-((i*(i-1))/2)+1);
        ans %=m;
 
    }
    ans+=1;
    cout << ans<<"\n";
}