#include<bits/stdc++.h>



#define ll long long
#define pb push_back
#define all(n) n.begin(),n.end()
#define eb emplace_back
#define endl "\n"
#define pll pair<ll,ll>
#define YES cout <<"YES"<<endl;
#define NO cout <<"NO"<<endl;
#define ff first
#define ss second
//do not use "\n" in interactive problem
//#define ((x|y)-y) (x&(~y))
//#define __gcd(fibo(x),fibo(y)=fibo(__gcd(x,y))
using namespace std;
const ll maxn=5e5+50;

const ll mod=1000000007;
const ll mod1=998244353;
ll a[maxn];


int main()
{
    //freopen("test.txt","r",stdin);
    // freopen("CHEMIST.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   ll n;
    cin>>n ;
    ll ans=0;

    for (int i=1;i<=n-1;i++)
    {
        ll x, y;
         cin>>x>>y;
         if (x>y) swap(x,y);
         ll t= n-y+1;

        ans=ans -x*t;
       // cout<<x<<" "<<t<<endl;
    }
    for (ll i=1;i<=n;i++)
    {

      ans=ans+(i)*(i+1)/2;

    }
    cout <<ans;

}
