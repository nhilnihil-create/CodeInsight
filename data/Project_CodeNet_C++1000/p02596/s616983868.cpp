#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define forn(i,n1, n2) for (ll i = n1; i < n2; i++)
#define w(t) ll t;cin>>t;while(t--)
#define en "\n"
#define f first
#define s second
const ll mod = 1000000007;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll k,sum=0,i;cin>>k;
    for(i=1;i<=1000005;i++)
    {
        sum*=10;
        sum+=7;
        if(sum%k==0){cout<<i;exit(0);}
        sum=sum%k;
    }
    cout<<-1<<en;
    return 0;
}