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
#define Precise cout.precision(7);
#define yes cout<<"YES"<<'\n'
#define no cout<<"NO"<<'\n'
using namespace std;

bool sortBysec(const pair<string,ll>&a,const pair<string,ll>&b)
{

    return (a.se>b.se);

}
int main()
{
    godspeed
    ll  t,n,m,x,i,j,k,l;
    string s;
    map<string,ll>v;
    cin>>t;
    while(t--)
    {
        cin>>s;
        v[s]++;
    }
    vector<pair<string,ll>>all;
    ll maxi=0;
    for(auto it:v)
    {
        maxi=max(it.se,maxi);
        all.pb(mp(it.fi,it.se));
    }
    sort(all.begin(),all.end(),sortBysec);
    vector<string>ans;
    for(auto lol:all)
    {
        if(lol.se==maxi)
            ans.pb(lol.fi);
        else break;
    }
    sort(ans.begin(),ans.end());
    for(auto u:ans)
        cout<<u<<en;
    return 0;
}




