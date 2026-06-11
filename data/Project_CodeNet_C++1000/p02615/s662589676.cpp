#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
struct player{
   ll l,r,comfort;
   player(ll left, ll right){
      l=left;
      r=right;
      comfort=min(l,r);
   }
   bool operator<(const player& x) const{
      return comfort<x.comfort;
   }
};
ll n,a[200005],ans;
priority_queue<player> q;
int main(){
   cin>>n;
   for(ll i=0;i<n;i++) cin>>a[i];
   sort(a,a+n);
   reverse(a,a+n);
   q.push(player(a[0],a[1]));
   ans=a[0];
   for(ll i=2;i<n;i++){
      player p=q.top();
      if(q.size()>1) q.pop();
      ans+=p.comfort;
      q.push(player(a[i],p.l));
      q.push(player(a[i],p.r));
   }
   cout<<ans;
   return 0;
}