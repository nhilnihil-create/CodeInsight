#include<bits/stdc++.h>
#define ll long long
#define pb push_back
long long int mod = (long long int)1000000007;
using namespace std;

void solve()
{
    ll i,j,k,n;
    std::cout.precision(10);
    int yes=0;
    ll a,b;
    cin>>a>>b;
    for(i=1;i<=1000000;i++)
    {
        if(int(i*(0.08))==a && int(i*(0.1))==b)
        {
            cout<<i;
            return;
        }
    }
    cout<<"-1";
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int i,j,k;
    int t;
    std::cout.precision(10);
    t=1;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
}