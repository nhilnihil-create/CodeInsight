#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ll_MAX LONG_LONG_MAX
#define ll_MIN LONG_LONG_MIN
#define pi pair<int,int>
#define endl "\n"
#define MAXN 100005
#define mod 1000000007
using namespace std;

void solve()
{
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    solve();
    string n;
    cin>>n;
    ll sum = 0;
    for(ll i=0; i<n.size(); i++)
    {
        sum += (int)n[i] - int('0');
    }
    // cout<<sum<<'\n';
    if(sum%9)
    {
        cout<<"No"<<'\n';
    }
    else
    {
        cout<<"Yes"<<'\n';
    }
    
}