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
    ll a,b,c;
    cin>>a>>b>>c>>k;
    ll sum=0;
    sum=min(k,a);
    k-=a;
    if(k>0)
    {
      
        k-=b;
    }
    if(k>0)
    {
        sum-=min(k,c);
        k-=c;
    }
    cout<<sum;
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