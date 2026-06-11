#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int a,b,c,d;
    cin>>a>>b>>c>>d;
    long long int ans=max(max(a*c,b*c),max(a*d,b*d));

    cout<<ans;
}
int main()
{
    solve();
}