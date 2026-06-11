#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long x,k,d;
    long long ans;
    cin>>x>>k>>d;
    x=abs(x);
    if(x/d>=k)
        ans=x-k*d;
    else if(x/d%2!=k%2)
        ans=d-x%d;
    else
        ans=x%d;
    cout<<ans<<endl;
    return 0;
}
