#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define idfc ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
//:/
#define pb push_back
#define mp make_pair
#define nt _ll128
#define ld double
long double PI =3.14159265;
using ll = long long;

const ll modo=1e9+7;
const ll ms=2e5+5;
const ll inf=1e17;


ll ar[ms];


ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}


int main()
{
    //idfc;
  //  freopen("h1.txt","r",stdin);

    int n;
    ll m;
    cin>>n>>m;
    int i;


    for(i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    sort(ar+1,ar+n+1);
    ll num=ar[1];
    ll kk=2e9;
    ll pp=1e9;
    kk*=pp;
   // cout<<kk<<"\n";
    ll lim=m*2;
    for(i=2;i<=n;i++)
    {
        num=(num*ar[i])/gcd(num,ar[i]);
        //cout<<num<<"\n";
        if(num>lim)
        {
            cout<<0;
            return 0;
        }
    }
    int x;
    for(i=1;i<=n;i++)
    {
        x=num/ar[i];
        if(x%2==0)
        {
            cout<<0;
            return 0;
        }
    }

    n=num/2;

    ll ans=(m/n)-(m/num);

    cout<<ans;

    return 0;
}