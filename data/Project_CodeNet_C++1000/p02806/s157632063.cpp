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
#define yes cout<<"Yes"<<'\n'
#define no cout<<"No"<<'\n'
using namespace std;

int main()
{
    godspeed
    ll  i,j,k,l,n,x,ans=0;
    cin>>n;
    vector<pair<string,ll>>v(n);
    string s,target;
    while(n--){
    cin>>s>>x;
    v.push_back(make_pair(s,x));
    }
    cin>>target;
    bool ok=0;
    for(i=0;i<v.size();i++)
    {
        if(ok) ans+=v[i].second;
        if(target==v[i].first){
            ok=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}



