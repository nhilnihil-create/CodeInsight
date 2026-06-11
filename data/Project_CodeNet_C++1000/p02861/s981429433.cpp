/*

 Remember, Hope is a good thing... May be the best of things... And No Good thing ever Dies !!!

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007
const ll inf=(1LL<<60)-1;
int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};
double x[10],y[10];
ll divCount(ll n)
{
    bool hash[n + 1];
    memset(hash, true, sizeof(hash));
    for (ll p = 2; p * p <=n; p++)
        if (hash[p] == true)
            for (ll i = p * 2; i <=n; i += p)
                hash[i] = false;
    int total = 1;
    for (ll p = 2; p <= n; p++)
    {
        if (hash[p])
        {
            ll count = 0;
            if (n % p == 0)
            {
                while (n % p == 0)
                {
                    n = n / p;
                    count++;
                }
                total = total * (count + 1);
            }
        }
    }
    return total;
}
double dist(int i,int j)
{
    double dx=x[i]-x[j];
    double dy=y[i]-y[j];
    return pow(dx*dx+dy*dy,0.5);
}
void solve()
{
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    vector<ll>a(n);
    for(ll i=0;i<n;i++)
        a[i]=i+1;
    ll fact=1;
    for(ll i=2;i<=n;i++)
        fact*=i;
        double sum=0.0;
    do
    {
        for(ll i=0;i<n-1;i++)
             sum+=dist(a[i],a[i+1]);
    }while(next_permutation(a.begin(),a.end()));
    cout<<fixed<<setprecision(10)<<sum/fact<<endl;
}
int main()
{
    IOS;
    //ll t;
    //cin>>t;
    //while(t--)
    solve();
    return 0;
}
