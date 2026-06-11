#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

#define all(v) v.begin(), v.end()

const ll mod=1000000007;

ll countBits(ll in){
  int res=0;
  for(;in>0;in>>=1){
    if((in&0x01)!=0){
      res++;
    }
  }
  return res;
}

template<typename T>
void show2dVector(vector<vector<T>>& v){
  for(int i=0;i<v.size();i++){
    int m=v[i].size();
    cout<<i<<" : ";
    for(int j=0;i<m;i++){
      cout<<v[i][j]<<" ";
    }
    cout<<endl;
  }
}

void bfs(const vector<vector<int>>&g, int v, vector<bool>& seen){
  seen[v]=true;
  cout<<v<<" ";
  for(auto next: g[v]){
    if(seen[next]){
      continue;
    }
    bfs(g,next,seen);
  }
}

bool dfs(vector<vector<int>> &g,int start,int goal,vector<bool>&seen){
  bool res=false;
  seen[start]=true;
  if(start==goal){
    return true;
  }
  for(auto next: g[start]){
    if(seen[next]){
      continue;
    }
    res=dfs(g,next,goal,seen);
    if(res){
      break;
    }
  }
  return res;
}

ll gcd(ll a,ll b) {
  return b? gcd(b,a%b): a;  
}
ll lcm(ll a,ll b) {
  return a*b/gcd(a,b);
}
bool isLowerCase(char c){
  return (c>='a'&&c<='z');
}

ll powm(ll a,ll n, ll m){
  ll ret=1;
  while(n>0){
    if(n%2==1){
      ret=(ret*a)%m;
    }
    n>>=1;
    a=(a*a)%m;
  }
  return ret;
}

const string yesno(bool ans){
  return (ans?"Yes":"No");
}
int main() {
  int h,w;cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++){
    cin>>s[i];
  }
  vector<vector<int>> l(h,vector<int>(w,0));
  vector<vector<int>> r(h,vector<int>(w,0));
  vector<vector<int>> d(h,vector<int>(w,0));
  vector<vector<int>> u(h,vector<int>(w,0));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='#'){
        l[i][j]=0;
        continue;
      }
      if(j==0){
        l[i][j]=1;
        continue;
      }
      l[i][j]=l[i][j-1]+1;
    }
  }
  for(int i=0;i<h;i++){
    for(int j=w-1;j>=0;j--){
      if(s[i][j]=='#'){
        r[i][j]=0;
        continue;
      }
      if(j==w-1){
        r[i][j]=1;
        continue;
      }
      r[i][j]=r[i][j+1]+1;
    }
  }
  for(int i=h-1;i>=0;i--){
    for(int j=0;j<w;j++){
      if(s[i][j]=='#'){
        d[i][j]=0;
        continue;
      }
      if(i==h-1){
        d[i][j]=1;
        continue;
      }
      d[i][j]=d[i+1][j]+1;
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='#'){
        u[i][j]=0;
        continue;
      }
      if(i==0){
        u[i][j]=1;
        continue;
      }
      u[i][j]=u[i-1][j]+1;
    }
  }
  int ans=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      int val=l[i][j]+r[i][j]+d[i][j]+u[i][j]-3;
      ans=max(ans,val);
    }
  }
  cout<<ans<<endl;
  return 0;
}
