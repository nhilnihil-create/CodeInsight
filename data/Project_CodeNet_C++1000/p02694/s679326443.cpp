#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;
void solve()
{
    ll x,temp=100,year=0;
    cin>>x;
    while(1)
    {
        if(temp>=x) break;
        year++;
        temp+=temp/100;
    }
    cout<<year;
}

int main()
{
    fast;
    int t;
    solve();
}
