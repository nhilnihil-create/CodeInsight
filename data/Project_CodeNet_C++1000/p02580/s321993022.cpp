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
#define pi pair<int,int>
#define F first
#define S second
#define pb push_back
#define pp pop_back
#define mod 1000000007
#define pai acos(-1)
#define N 300005

int tree[4*N];
vector<int>G[N];


void update(int node,int b,int e,int idx,int val){
   if(idx<b||idx>e) return ;
   if(b==e){
     tree[node]+=val;
      return ;
   }
   int mid=(b+e)/2;
   update(2*node,b,mid,idx,val);
   update(2*node+1,mid+1,e,idx,val);
   tree[node]=max(tree[2*node],tree[2*node+1]);
}


int main ()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int h,w,m;cin>>h>>w>>m;
   for(int i=1;i<=m;i++){
      int x,y;cin>>x>>y;
      G[x].pb(y);
      update(1,1,w,y,1);
   }
   int ans=0;
   for(int i=1;i<=h;i++){
      if(G[i].size()){
         int cnt=G[i].size();
         for(int v:G[i]) update(1,1,w,v,-1);
         cnt+=tree[1];
         ans=max(cnt,ans);
         for(int v:G[i]) update(1,1,w,v,1);
      }
   }
   cout<<ans<<endl;
   return 0;
}

