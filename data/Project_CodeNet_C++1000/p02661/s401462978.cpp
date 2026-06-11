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
    cin>>n;
    ll a[n],b[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    ll x,y;
    if(n%2==1)
    {
        x=a[(n-1)/2];
        y=b[(n-1)/2];
    }
    else
    {
        x=a[(n-2)/2]+a[(n)/2];
        y=b[(n-2)/2]+b[n/2];
    }
    cout<<y-x+1;
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