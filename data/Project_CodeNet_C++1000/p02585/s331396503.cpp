#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <chrono> 
using namespace std::chrono;
using namespace std;
typedef long long ll;
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_mset tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update> 
#define fr(i,a,b) for (ll i=(a); i<(b);++i)
#define frr(i,a,b) for(ll i=(a-1);i>=(b);--i)
#define vi vector<ll>
#define vl vector<ll>
#define pb push_back
#define ppb pop_back()
#define pf push_front
#define ppf pop_front()
#define F first
#define S second
#define pii pair<ll,ll> 
#define rev(a) reverse(a.begin(),a.end())
#define srt(a,k) sort(a,a+k,greater<ll>())
#define rsrt(a) sort(a.begin(),a.end(),greater<ll>())
#define sz(a) (ll)a.size()
//#define endl "\n"
#define po(a,b) (ll)(pow(a,b)+0.5)
#define double long double
#define print(a) for(auto x:a)cout<<x<<" ";cout<<endl;
#define setbits(a) __builtin_popcount(a)
const ll M=1e9+7;
const ll MX=1e6+1;

int n,k;
ll p[5001],c[5001];
bool vis[5001];vl fin1;
void dfs(int i)
{
    if(vis[i])return;
    vis[i]=true;
    fin1.pb(c[i]);
    dfs(p[i]);
}
int main()
{  
     
  int tt=1;
  //cin>>tt;
  while(tt--)
  {
    cin>>n>>k;
    
    fr(i,1,n+1)cin>>p[i];
    fr(i,1,n+1)cin>>c[i];
    fr(i,1,n+1)vis[i]=false;

    ll ans=-1e18;
    fr(i,1,n+1)
    {
        if(!vis[i])
        {
           fin1.clear();
           dfs(i);
          fr(i1,0,sz(fin1))
          {
           vi fin;
           fr(k1,i1,sz(fin1))fin.pb(fin1[k1]);
           fr(k1,0,i1)fin.pb(fin1[k1]);
           fr(j,1,sz(fin))
           {
              fin[j]+=fin[j-1];
           }         
              ll cur_ans;
            if(sz(fin)>=k)
            {
               cur_ans=fin[0];
               fr(i,1,k)cur_ans=max(cur_ans,fin[i]);
            }
            else
            {
               if(fin.back()>0)
               {
                  cur_ans=(k/sz(fin))*fin.back();
                  ll cnt=0;
                  fr(i,0,k%sz(fin))cnt=max(cnt,fin[i]);
                  cur_ans+=cnt;

                  ll another=((k/sz(fin))-1)*fin.back();
                   cnt=0;
                  fr(i,0,sz(fin))cnt=max(cnt,fin[i]);
                  another+=cnt;
                  cur_ans=max(cur_ans,another);
               }
               else
               {   cur_ans=fin[0];
                   fr(i,1,sz(fin))cur_ans=max(cur_ans,fin[i]);
               }
            }
           ans=max(ans,cur_ans);
        }
      }
    } 
    cout<<ans; 

  }
}

