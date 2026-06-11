#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define db long double
#define all(a) a.begin(),a.end()
#define f(i,l,u) for(ll i=l;i<u;i++)
#define lb lower_bound
#define ub upper_bound
#define pb push_back

int main() {
ll s=0;
ll n;
cin>>n;
f(i,1,n+1)
{
    ll x;
    cin>>x;
    if(i%2&&x%2)
    s++;
}
cout<<s<<endl;
    
    
    return 0;
}