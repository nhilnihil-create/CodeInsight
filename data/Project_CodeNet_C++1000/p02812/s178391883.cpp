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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll cnt = 0;
    for(ll i=0; (i + 3)<=n; i++)
    {
        if(s[i] == 'A' && s[i + 1]=='B' && s[i+2] == 'C')
            cnt++;
    }
    cout<<cnt<<'\n';
}