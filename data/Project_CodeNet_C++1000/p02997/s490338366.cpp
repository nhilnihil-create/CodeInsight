#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
  int N,K; cin>>N>>K;
  //n-1 c 2 + n-2 = n-2 n+1 / 2
  if(K > (N-1)*N/2 - (N-1)){
    cout<<-1<<endl;
    return 0;
  }
  int k = (N-1)*(N-2)/2;//必要なペア数
  vector<pair<int,int>> res;
  rep1(i,N)res.push_back(make_pair(1,i+1));
  for(int i = 2; i < N; i++){
    if(K==k)break;
    for(int j = i+1; j <= N; j++){
      k--;
      res.push_back(make_pair(i,j));
      if(K==k)break;
    }
  }
  cout<<res.size()<<endl;
  for(auto p: res){
    cout<<p.first<<" "<<p.second<<endl;
  }
  return 0;
}