
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
int n;
long long k;
vector<int> c;
void dfs(int node){
  visited[node]=1;
   c.emplace_back(node);
  for(auto next:adj[node]){
    if(!visited[next]){
      dfs(next);
    }else{
      ender=next;
      break;
    }
  }
 
}

int main() {
   fast();
   cin>>n;
   cin>>k;
   for(int i=0;i<n;i++){
    int l;
    cin>>l;
    --l;
    adj[i].emplace_back(l);
   }
   dfs(0);
  
  
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
 
