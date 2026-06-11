#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 200003
#define MOD 1000000007
#define INF 1000000000000000000

int main(){
  int N,K;
  cin>>N>>K;
  vector<ll> H(N);
  for(int i=0;i<N;i++){
    cin>>H.at(i);
  }

  vector<vector<ll>> dp(N,vector<ll>(N+1,INF));
  for(int i=0;i<N;i++){
    dp.at(i).at(0)=0;
    dp.at(i).at(1)=H.at(i);
  }
  for(int j=2;j<=N;j++){
    for(int i=1;i<N;i++){
      for(int k=0;k<i;k++){
        dp.at(i).at(j)=min<ll>(dp.at(i).at(j),dp.at(k).at(j-1)+max<ll>(0,H.at(i)-H.at(k)));
      }
    }
  }

  ll ans=INF;
  for(int i=0;i<N;i++){
    ans=min<ll>(dp.at(i).at(N-K),ans);
  }
  cout<<ans<<endl;
}
