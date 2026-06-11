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
    ll m=1000000000000000000;
    for(i=-1200;i<=1200;i++)
    {
        for(j=-1200;j<=1200;j++)
        {
            if(pow(i,(ll)5)==pow(j,(ll)5)+n)
            {
                cout<<i<<" "<<j;
                return;
            }
        }
    }
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