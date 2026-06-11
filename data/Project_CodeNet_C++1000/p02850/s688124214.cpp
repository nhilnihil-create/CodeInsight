#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long int ll;
typedef pair<int, int> P;
typedef long double ld;
void Ans(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}

const ll INF=1001001001;
const ll mod=1000000007;

int main(){
  int n;cin>>n;
  vector<P> v[n];
  int a,b;
  rep(i,n-1){
    cin>>a>>b;
    a--;
    b--;
    v[a].push_back(P(b,i));
    v[b].push_back(P(a,i));
  }
  ll at[n];
  ll ans[n-1];
  rep(i,n-1) ans[i]=0;
  rep(i,n) at[i]=INF;
  int an=0;
  queue<int> q;
  rep(i,n){
    int cnt=1;
    if(at[i]!=INF) continue;
    q.push(i);
    int now;
    while(!(q.empty())){
      now=q.front();q.pop();
      if(at[now]==1){
        continue;
      }
      at[now]=1;
      cnt=1;
      int u=0;
      for(P j:v[now]){
        if(ans[j.se]>0) u=ans[j.se];
        //cout<<u<<endl;
      }
      for(P j:v[now]){
        if(u==cnt) cnt++;
        if(ans[j.se]>0) continue;
        ans[j.se]=cnt;
        an=max(an,cnt);
        q.push(j.fi);
        cnt++;
        //cout<<j.fi<<endl;
      }
    }
  }
  
  cout<<an<<endl;
  rep(i,n-1) cout<<ans[i]<<endl;
}