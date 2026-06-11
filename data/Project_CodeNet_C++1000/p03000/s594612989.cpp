#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define fr(i,a,b) for(ll i=a; i<b; i++)
#define rf(i,a,b) for(ll i=a; i>=b; i--)
#define pb push_back
#define mp make_pair
#define show(a) for(auto el:a)cout<<el<<" "
#define ff first
#define ss second
#define ppair vector<pair<ll,ll>>
#define vec vector <ll> 
#define all(a) a.begin(),a.end()
#define mo 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll test;
     ll n,i,x;
     cin>>n>>x;
     ll c=1,s=0,l;
     fr(i,0,n)
     {
         cin>>l;
         s=s+l;
         if(s<x || s==x)
         {
             c++;
             
         }
         else
         break;
     }
    cout<<c;
     return 0;
}