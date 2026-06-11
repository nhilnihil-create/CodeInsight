#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define all(v) v.begin(),v.end()
#define sz size()
#define mp make_pair
#define pb push_back
#define rep(p,a,b) for(ll p=a ; p<b ; p++)
#define rap(p,a,b) for(ll p=a ; p<=b ; p++)
#define per(p,a,b) for(ll p=a ; p>=b ; p--)
#define F first
#define S second
using namespace std;

typedef vector <ll> vll;
typedef vector <ld> vld;
typedef pair< ll ,ll > pll;


int main()
{
    ll t,i,j,k,ans,n;

    //cin>>t;
    t=1;
    while(t--)
    {
        ll h,sum=0;
        cin>>n>>k;
        vll v(n);
        rep(p,0,n)cin>>v[p];
        sort(all(v));

        rep(p,0,n-k)sum += v[p];
        cout<<sum;
    }
    
    return 0;
}