#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define speed ios_base::sync_with_stdio(0); cin.tie(0);
#define FL(i,a,n) for(ll i=a;i<n;i++)
#define even(x) (((x)%(2))==(0))
#define odd(x) (((x)%(2))==(1))
#define meme(x) memset(x, 0, sizeof(x))

#define pb push_back
#define mp make_pair
#define ff first
#define ss second


int main()
{
    int n;cin>>n;
    double ans=0;
    double a[n];for(int i=0;i<n;i++)cin>>a[i];
    a[0]=2*a[0];
    ans=a[0];
    for(int i=0;i<n;i++)
    {
        ans=(ans*a[i])/(ans+a[i]);
    }
    cout<<fixed<<setprecision(15)<<ans<<endl;
}
