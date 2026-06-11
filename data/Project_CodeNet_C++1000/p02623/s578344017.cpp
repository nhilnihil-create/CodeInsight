#include <bits/stdc++.h>
using namespace std;
typedef long long       ll;
const ll  big =1e7+2;
 ll n,m,k;
ll pref1[big],pref2[big];
ll bsfind(ll res){
  ll low=0,high=m,ans=0;
  while(low<=high){
    ll mid=(low+high)/2;
    if(pref2[mid]<=res){
        low=mid+1;
        ans=mid;
    }
    else{high=mid-1; }
  }

  return ans;
  }
int main()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

ll ans=0,can;
cin>>n>>m>>k;
ll x;
cin>>x;
pref1[1]=x;
for(int i=2;i<=n;++i){
        ll x;cin>>x;
    pref1[i]=pref1[i-1]+x;

    }
ll y;cin>>y;
    pref2[1]=y;
for(int i=2;i<=m;++i){
        ll x;cin>>x;
    pref2[i]=pref2[i-1]+x;

    }
for(int i=0;i<=n;++i){
    ll rest=k-pref1[i];
    if(rest<0){
        break;
    }
 
    can=bsfind(rest);
    ans=max(ans,i+can);
    }




cout<<ans;
    return 0;
}