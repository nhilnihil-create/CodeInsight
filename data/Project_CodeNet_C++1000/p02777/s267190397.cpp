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
        map<string,ll> m;
        string s1,s2,s3;
        ll x,y;
        cin>>s1>>s2>>x>>y>>s3;

        if(s1==s3)x--;
        else y--;
        cout<<x<<" "<<y;
        
    }
    
    return 0;
}