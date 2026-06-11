#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
int n,k;
struct Node{
  int no;
  int par;
  vector<Node*> child;
  void build(int i){
    no=i;
    par=i;
  }
};
signed main(){
  cin>>n>>k;
  vector<Node> node(n+1);
  rep(i,n-1){
    int a,b;cin>>a>>b;
    node[a].child.push_back(&node[b]);
    node[b].child.push_back(&node[a]);
  }
  int res=k;
  rep1(i,n)node[i].build(i);
  queue<Node> que;
  que.push(node[1]);
  while(!que.empty()){
    Node buf=que.front();que.pop();
    int num=buf.child.size();
    int cur=2;
    if(buf.par==buf.no)cur=1;
    rep(i,num){
      if(buf.child[i]->no!=buf.par){
        buf.child[i]->par=buf.no;
        res*=(k-cur);
        res%=MOD;
        cur++;
        que.push(*buf.child[i]);
      }
    }
  }
  cout<<res<<"\n";
  return 0;
}
