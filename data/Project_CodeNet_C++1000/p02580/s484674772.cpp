//@sakshjha
#include<bits/stdc++.h>
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

#define ll long long int
#define ld long double
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pi 3.14159265358979
#define pa pair<ll,ll>
//#define goodset tree<pa, null_type, less<pa>, rb_tree_tag, tree_order_statistics_node_update>
//#define FRE freopen("acm.in","r",stdin); freopen("acm.out","w",stdout);

const ll mod = 1e9+7 ;
const ll N = 1e3+7;
char maz[N][N];
ll vis[N][N],dis[N][N];

int main()
{
    FAST
    ll tc,i,j,k;
    //cin>>tc;
    tc=1;
    while(tc--)
    {
       ll n,m,tar;
       cin>>n>>m>>tar;
       map<ll,ll>mp,mp1,mp2;
       vector<pair<ll,ll> >v;
       for(i=0; i<tar; i++)
       {
           ll r,c;
           cin>>r>>c;
           v.pb({r,c});
           mp[r]++;
           mp1[c]++;
           mp2[c]++;
       }
       sort(v.begin(),v.end());
       multiset<ll>s;
       for(auto it: mp1)
        s.insert(it.second);

        set<ll>s1;
        ll ans=0;
       for(i=0; i<tar; i++)
       {
           ll fir=v[i].first;
           ll cnt=mp[fir];
           s1.clear();
            /*if(cnt==4)
           {
               for(auto it: s)
                cout<<it<<"\n";
               cout<<"\n";
           }*/
           for(j=i; j<i+cnt; j++)
           {
               ll val=mp1[v[j].second];
               mp1[v[j].second]--;

               s.erase(s.find(val));
               s.insert(val-1);
               s1.insert(v[j].second);
           }
           //cout<<s.size()<<"\n";
           ll cnt2=*s.rbegin();


           //cout<<"\n";
           ans=max(ans,cnt+cnt2);
           //cout<<cnt<<" "<<cnt2<<"\n";
           for(auto it : s1)
           {
               ll val=mp1[it];
               s.erase(s.find(val));
               mp1[it]=mp2[it];
               s.insert(mp1[it]);
           }
           i=i+cnt-1;
           //cout<<ans<<"\n";
       }

       cout<<ans;



    }
    return 0;
}



