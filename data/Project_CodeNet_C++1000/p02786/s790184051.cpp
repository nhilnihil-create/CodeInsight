#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long int n,ans=0,x=1;
    cin>>n;
    while(n)
    {
        ++ans;
        n/=2;
        x*=2;
    }
    cout<<x-1;
}

