#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ll long long 
#define mod 1000000007 
void fast(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
}
void setIO(string name) {
  freopen((name+".in").c_str(),"r",stdin);
  freopen((name+".out").c_str(),"w",stdout);
}
vector<int> adj[200005];
int visited[200005]={0};
int ender=-1;
int cnt=1;
vector<int> c;
void dfs(int node,int length){
  visited[node]=length;
   c.pb(node);
  cnt=max(cnt,length);
  for(int next:adj[node]){
    if(!visited[next]){
      
      dfs(next,length+1);

    }else{
      ender=next;
    }
  }
  cnt=max(cnt,length);

}

int main() {
   fast();
   //setIO("moop");
   int n;
   cin>>n;
   long long k;
   cin>>k;
   for(int i=0;i<n;i++){
    int l;
    cin>>l;
    --l;
    adj[i].pb(l);
   }
   dfs(0,1);
   int length_of_cycle;
   if(ender!=-1){
     int x;
      for(int i=0;i<c.size();i++){
        if(c[i]==ender){
           x=i;
           break;
        }
      }
     if(k<=x){
       cout<<c[k]+1<<"\n";
       return 0;
     }else{
      long long y=c.size()-x;
      k-=x;
      k%=y;
      cout<<c[k+x]+1<<"\n";
      return 0;
     }
      
   }

   

   

   
   



   
}
 