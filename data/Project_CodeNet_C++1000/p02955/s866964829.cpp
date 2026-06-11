#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 300003
#define MOD 998244353
#define INF 1000000000000000

int main(){
  int N;
  ll K;
  cin>>N>>K;
  vector<ll> A(N);
  ll sum=0;
  for(int i=0;i<N;i++){
    cin>>A.at(i);
    sum+=A.at(i);
  }
  vector<ll> div;
  for(ll i=1;i*i<=sum;i++){
    if(sum%i==0){
      div.push_back(i);
      if(i!=sum/i){
        div.push_back(sum/i);
      }
    }
  }
  sort(div.begin(),div.end());
  reverse(div.begin(),div.end());

  int i=0;
  while(true){
    vector<ll> B(N);
    for(int j=0;j<N;j++){
      B.at(j)=A.at(j)%div.at(i);
    }
    sort(B.begin(),B.end());
    vector<ll> sum1(N+1,0),sum2(N+1,0);
    for(int j=0;j<N;j++){
      sum1.at(j+1)=sum1.at(j)+B.at(j);
      sum2.at(j+1)=sum2.at(j)+(div.at(i)-B.at(j))%div.at(i);
    }

    ll sum=sum1.at(N);
    for(int j=0;j<N;j++){
      sum=min<ll>(sum,max<ll>(sum1.at(j),sum2.at(N)-sum2.at(j)));
    }
    if(sum<=K){
      cout<<div.at(i)<<endl;
      break;
    }
    i++;
  }
}
