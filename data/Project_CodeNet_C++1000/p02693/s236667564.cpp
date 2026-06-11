#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;
void solve()
{
    int k,a,b;
    cin>>k>>a>>b;
    if((b/k)*k>=a)
    {
        cout<<"OK";
    }
    else cout<<"NG";
}

int main()
{
    fast;
    int t;
    solve();
}
