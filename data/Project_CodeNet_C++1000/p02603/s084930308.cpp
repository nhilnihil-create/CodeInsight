#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define all(v) (v).begin(), (v).end()
using namespace std;



std::vector<ll> v;
void solve()
{
    ll n;
    cin >> n;
    v.resize(n);
    for(auto &i : v) cin >> i;
    ll m=1000,x;
    for(int i=0;i+1<n;i++)
    {
        x=m/v[i];
        m+=max(x*(v[i+1]-v[i]),0ll);
    }    
    cout<<m;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int TESTS = 1;
    // cin >> TESTS;
    while(TESTS--)
    {
        solve();

    }
    return 0;
}