#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define ff first
#define ss second
#define p pair<ll,ll>
#define pb push_back
#define endl '\n'
#define w(t) ll test;cin>>test;while(test--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define iof  freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define pi acos(-1)
const int mxn=1e9+5;
int main()
{
    fast;
    ll a;
    ll b1,b2;
    char c;
    cin>>a>>b1>>c>>b2;
    ll b=b1*100+b2;
    //ll c=b;
    //cout<<b<<endl;
    ll ans=a*b;
    ans=ans/100;
    cout<<ans<<endl;

}

