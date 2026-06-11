#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

using namespace std;

typedef long long ll;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pb_ds;

#define IN freopen("in.txt","r",stdin)
#define OUT freopen("out.txt","w",stdout)
#define pi pair<ll,int>
#define F first
#define S second
#define pb push_back
#define pp pop_back
#define eps 10E-10
#define mod 1000000007
#define pai acos(-1)
#define N 25

vector<int>hst[N],dishst[N];

bool check_bit(int mask,int k){
   return (mask>>k)&1;
}

int main ()
{
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
   int n;
   cin>>n;
   for(int i=1;i<=n;i++){
      int m;cin>>m;
      while(m--){
         int x,y;cin>>x>>y;
         if(y) hst[i].pb(x);
         else dishst[i].pb(x);
      }
      sort(hst[i].begin(),hst[i].end());
      sort(dishst[i].begin(),dishst[i].end());
   }
   int ans=0;
   for(int mask=0;mask<(1<<n);mask++){
      set<int>sth,stdh;
      for(int i=0;i<n;i++){
         if(check_bit(mask,i)) sth.insert(i+1);
         else stdh.insert(i+1);
      }
      bool ok=1;
      for(int i=1;i<=n;i++){
         if(check_bit(mask,i-1)){
            for(int v:hst[i]){
               if(stdh.find(v)!=stdh.end()) ok=0;
            }
            for(int v:dishst[i]){
               if(sth.find(v)!=sth.end()) ok=0;
            }
         }
      }
      if(ok) ans=max(ans,(int)sth.size());
   }
   cout<<ans<<endl;
   return 0;
}
