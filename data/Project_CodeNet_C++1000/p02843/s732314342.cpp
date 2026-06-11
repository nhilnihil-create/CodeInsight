#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,ans=0;
    cin>>n;
    k = n/100;
    if(n>=k*100&&n<=k*105)
        ans=1;
    if(n<100)
        ans=0;
    cout<<ans;
    return 0;
}
