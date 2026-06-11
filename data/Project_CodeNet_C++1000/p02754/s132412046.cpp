#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long int n,a,b;
    cin>>n>>a>>b;
    
    long long int ans=n/(a+b)*a;
    n%=(a+b);

    if (n>=a)
    {
        cout<<ans+a<<endl;
    }
    else
    {
        cout<<ans+n<<endl;   
    }
    
}