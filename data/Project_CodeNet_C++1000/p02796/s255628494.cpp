//Radhe Radhe
#include<bits/stdc++.h>
#define godspeed  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define rep1(i,a,b)    for(ll i=a; i<=b; i++)
#define repVect(i,n)    for(ll i=0; i<sum.size(); i++)
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
#define yes cout<<"Yes"<<'\n';
#define no cout<<"No"<<'\n';
using namespace std;

int main()
{
    godspeed
    ll  t,i,x,y,j,k,n;
    string s;
    cin>>n;
    vector<pair<ll,ll>>v;
    for(i=0; i<n; i++)
    {
        cin>>x>>y;
        v.push_back(mp(x+y,x-y));
    }
    sort(v.begin(),v.end());
    ll discard=0,cur;
    cur=v[0].fi;
    for(i=1; i<v.size(); i++)
    {
       ll q=v[i].se;
       if(cur>q) discard++;
       else cur=v[i].fi;
    }

    cout<<n-discard<<endl;
    return 0;
}



