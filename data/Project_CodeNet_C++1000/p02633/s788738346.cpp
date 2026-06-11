//Abhinav ---IIIT_A
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define f(i,x,n) for(int i=x;i<(int)n;++i)
#define vpii vector<pair<int,int>> 
#define vi vector<int>
#define all(x) x.begin(),x.end()
ld pie=3.141592653589793238462643383279;
int mod=1e9+7;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};


int fact[2000005];
int infact[2000005];

int inv(int a){
  int y=mod-2;
  int r=1;
  while(y!=0){
    if(y&1){
      r*=a; r%=mod;
    }
    y/=2; a*=a; a%=mod;
  }
  return r;
}

int po(int a,int y){
  int r=1;
  while(y!=0){
    if(y&1){
      r*=a; r%=mod;
    }
    y/=2; a*=a; a%=mod;
  }
  return r; 
}

void facto(){
  fact[0]=1;
  f(i,1,2000005) {fact[i]=i*fact[i-1]; fact[i]%=mod;}
  f(i,0,2000005) infact[i]=inv(fact[i]); 
}

int nck (int n,int k){
  if(k<0 || k>n) return 0;
  int ret=fact[n]; ret*=infact[k]; ret%=mod;
  ret*=infact[n-k]; ret%=mod;
  return ret;
}

int n,m;

vector<int> adj[1000005];
bool vis[1000005];
bool vis2[1000005];
int ans[1000005];

bool poss=1;

int dfs(int c,int p){
  bool lp=1;
  int leaf=0;
  for(auto it : adj[c]){
    if(it!=p){
      lp=0;
      leaf+=dfs(it,c);
    }
  }
  if(lp) return 1;
  else{
    if(leaf<3) poss=0;
    return 0;
  }
  
}

void dfs2(int s,int val){
  if(vis2[s]) return ;
  vis2[s]=1; ans[s]=val;
  for(auto it : adj[s])
    dfs2(it,val);
}

int rev(int a){
  int r=0;
  while(a!=0){
    r+=a%10;
    r*=10;
    a/=10;
  }
  return r/10;
}
int32_t main(){ 

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  facto();
  int n; cin>>n;
  f(i,1,361) {
    if((i*n)%360==0){
      cout<<i;
      return 0;
    }
  }
  return 0;
}
