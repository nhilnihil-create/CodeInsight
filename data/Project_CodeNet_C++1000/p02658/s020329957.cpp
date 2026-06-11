//Radhe Radhe
#include<bits/stdc++.h>
#define godspeed  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define limit 1000000000000000000 //1e18
#define mod 1000000007 //1e9+7
#define llu long long unsigned
#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,n)    for(ll i=0; i<n; i++)
#define rep1(i,a,b)    for(ll i=a; i<b; i++)
#define repV(i,n)    for(ll i=0; i<v.size(); i++)
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
#define yes cout<<"Yes"<<'\n';
#define no cout<<"No"<<'\n';
using namespace std;

int main()
{
    godspeed
    llu  i,j,n,k,x,mult=1;
    cin>>n;
    bool zero=0;
    vector<llu>v(n);
    for(i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]==0)
            zero=1;
    }
    if(zero)
       return cout<<0<<endl,0;

    for(i=0;i<n;i++)
    {
        if(limit/mult>=v[i])
        {
            mult*=v[i];
        }
        else
            return cout<<"-1"<<endl,0;

    }

        cout<<mult<<endl;

    return 0;
}
