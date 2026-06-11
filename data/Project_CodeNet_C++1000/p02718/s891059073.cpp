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
    double m,a[n];
    cin>>m;
    double sum=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    double lim=sum/((double)4*m);

    ll c=0;
    for(i=0;i<n;i++)
    {
        //cout<<a[i]/sum;
        if(a[i]>=lim)
        {
            c++;
        }
    }
    if(c>=m)
    cout<<"Yes";
    else
    cout<<"No";
    
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