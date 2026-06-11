#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 800000000
#define MAX 1000

int main(){
  int  N,K;
  cin>>N>>K;
  vector<ll> A(N),sum(N+1,0);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
    sum.at(i+1)=sum.at(i)+A.at(i);
  }
  for(int i=0;i<=N;i++){
    sum.at(i)-=i;
    sum.at(i)%=K;
  }
  map<int,ll> m;
  for(int i=0;i<=N;i++){
    if(m.count(sum.at(i))==0){
      m[sum.at(i)]=0;
    }
    m[sum.at(i)]++;
  }
  map<int,ll> count;
  for(auto x:m){
    count[x.first]=0;
  }
  for(int i=0;i<=min(K-2,N);i++){
    count[sum.at(i)]++;
  }

  ll ans=0;
  for(int i=0;i<=N;i++){
    if(i+K-1<=N){
      count[sum.at(i+K-1)]++;
    }
    ans+=count[sum.at(i)]-1;
    count[sum.at(i)]--;
  }
  cout<<ans<<endl;

}
