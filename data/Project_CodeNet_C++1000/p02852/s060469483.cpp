#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);++i)
#define fi first
#define se second
#define INF 1000000009
#define lINF 1000000000000000009
typedef long long ll;
int d[100009];

int main(){
  int n,m;
  string s;
  vector<int>x;
  
  cin>>n>>m>>s;
  n++;
  reverse(s.begin(),s.end());

  rep(i,n){
    if(s[i]=='0'){
      x.push_back(i);
    }
    d[i]=INF;
  }
  d[0]=0;
  for(int i=1;i<n;i++){
    if(s[i]=='1')continue;
    int idx=upper_bound(x.begin(),x.end(),i-m-1)-x.begin();
    int nx=x[idx];
    if(nx<i&&d[nx]<INF){
      d[i]=d[nx]+1;
    }
  }

  /*rep(i,n){
    cout<<d[i]<<' ';
  }
  cout<<endl;*/

  vector<int>ans;
  int now=d[n-1],xnow=n-1;
  for(int i=n-1;i>=0;i--){
    if(d[i]+1==now){
      ans.push_back(xnow-i);
      now--;
      xnow=i;
    }
  }

  if(d[n-1]==INF){
    cout<<-1<<endl;
    return(0);
  }
  rep(i,ans.size()){
    cout<<ans[i];
    if(i+1==ans.size())cout<<endl;
    else cout<<' ';
  }

  return(0);
}
