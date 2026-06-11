#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double
#define vpii vector<pair<int,int> >
#define X first
#define Y second
#define fr(i,a,n) for(int i=a;i<n;i++)
#define mod 1000000007
#define fi ios_base::sync_with_stdio(false);cin.tie(NULL);



int main()
{
    ll a,b,n;
    cin>>a>>b>>n;
    ll x=min(n,b-1);
    cout<<(x*a)/b;
}