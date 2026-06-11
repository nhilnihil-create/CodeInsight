#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    long long int n,a,b,ans=0;
    cin>>n>>a>>b;
    ans+=(n/(a+b))*a;
    n=n%(a+b);
    if(n<=a) ans+=n;
    else ans+=a;
    cout<<ans;
}