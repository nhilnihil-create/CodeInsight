#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,a,b;
    cin>>n>>a>>b;
    if(a==0)
    {
        cout<<0<<endl;
        return 0;
    }
    long long int ans=(n/(a+b));
    long long int rem=n%(a+b);
    if(rem<=a)
     ans=ans*a+rem;
    else
     ans=ans*a+a;
    cout<<ans<<endl;
}