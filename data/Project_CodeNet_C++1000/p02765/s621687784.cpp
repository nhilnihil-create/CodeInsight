#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,r;
    cin>>n>>r;
    if(n>=10)
     cout<<r<<"\n";
    else
     cout<<r+(100*(10-n))<<"\n";
}