#define ll long long
#define pi acos(-1.0)
#define Go "\n"
#define Afor(i,a,b) for( i=a;i<b;i++)
#define GCD __gcd
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<ll,ll>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,i;
    cin>>n;
    pll a[n];

    Afor(i,0,n)
    {
        cin>>a[i].ff;
        a[i].ss=i;
    }
    sort(a,a+n);
        Afor(i,0,n)
    {
        cout<<a[i].ss+1<<" ";
    }
    cout<<"\n";


}
