#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define Int long long




int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Int n;
    cin>>n;
    Int cv=0;
    for(Int i = 1;i<=n;i++)
    {
        cv+=(i)*(n-i+1);
    }
    for(Int i = 1;i<n;i++)
    {
        Int x,y;
        cin>>x>>y;
        cv-=(min(x,y)*(n-max(x,y)+1));
    }
    cout<<cv<<endl;;
}
