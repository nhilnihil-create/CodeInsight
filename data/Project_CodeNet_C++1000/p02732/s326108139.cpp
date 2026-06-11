//Radhe Radhe
#include<bits/stdc++.h>
#define godspeed  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define en '\n'
#define rep(i,n)    for(ll i=0; i<n; i++)
#define rep1(i,a,b)    for(ll i=a; i<=b; i++)
#define repVect(i,n)    for(ll i=0; i<sum.size(); i++)
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(1);
#define yes cout<<"YES"<<'\n'
#define no cout<<"NO"<<'\n'
using namespace std;

int main()
{
    godspeed
    ll i,n,k;
    string s;
    map<ll,ll>v;
    cin>>n;
    ll a[n];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        v[a[i]]++;
    }
    ll sum=0;
    for(auto it:v)
    {
        ll tmp=it.se;
        sum+=(tmp*(tmp-1))/2;
    }

    for(i=0; i<n; i++)
    {
        ll tmp=sum-v[a[i]]+1;
        cout<<tmp<<en;
    }

    return 0;
}
