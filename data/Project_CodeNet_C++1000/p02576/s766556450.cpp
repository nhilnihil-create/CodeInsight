#include <bits/stdc++.h>
using namespace std;

int main()
{
    

    int N,X,T,ans;
    cin>>N>>X>>T;

    if(N%X==0)
        ans=(N/X)*T;
    else ans = (N/X+1)*T;
    cout<<ans;

    return 0;
}