#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

int main() {
  int n;
  cin>>n;
  vector<vector<int>> IDs(n, vector<int>(n,-1));
  int id=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      IDs[i][j]=id;
      IDs[j][i]=id;
      id++;
    }
  }
  vector<vector<int>> G(n*(n-1)/2);
  vector<int> h(n*(n-1)/2,0);
  vector<int> length(n*(n-1)/2,-1);
  int t,bufid,vsid;
  for(int i=0;i<n;i++){
    bufid=-1;
    for(int j=0;j<n-1;j++){
      cin>>t;t--;
      vsid=IDs[i][t];
      if(bufid!=-1){
        G[bufid].push_back(vsid);
        h[vsid]++;
      }
      bufid=vsid;
    }
  }
  queue<int> que;
  vector<int> ans;
  for(int i=0;i<n*(n-1)/2;i++){
    if(h[i]==0) {
      que.push(i);
      length[i]=0;
    }
  }
  while(!que.empty()){
    int cur=que.front();
    que.pop();
    ans.push_back(cur);
    for(int next:G[cur]){
      h[next]--;
      length[next]=max(length[next],length[cur]+1);
      if(h[next]==0) que.push(next);
    }
  }
  bool cannot= (int)(ans.size())==n*(n-1)/2;
  if(!cannot) cout<<-1<<endl;
  else{
    int tem=*max_element(length.begin(),length.end());
    cout<<tem+1<<endl;
  }
  return 0;
}
