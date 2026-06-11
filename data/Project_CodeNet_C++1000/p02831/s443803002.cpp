#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define v(x) vector<int> x;
#define all(x) x.begin(),x.end()
#define s(x,n) memset(x,n,sizeof(x));
#define pb(x) push_back(x)
ll gcd(ll m,ll n)
{
    if(n==0)
        return m;
    else
        return gcd(n,m%n);
}
using namespace std;
int main()
{
    ll a,b;
    cin>>a>>b;
    cout<<(a*b)/gcd(a,b)<<"\n";
}