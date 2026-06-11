#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 300003
#define MOD 1000000007
#define INF 1000000000000000000

int main(){
  int N;
  cin>>N;
  vector<ll> A(N);
  vector<ll> sum(N+1,0);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
    sum.at(i+1)=sum.at(i)+A.at(i);
  }

  ll ss=sum.at(N);
  ll ans=INF;
  for(int i=0;i<=N;i++){
    ans=min<ll>(ans,abs<ll>(ss-2*sum.at(i)));
  }
  cout<<ans<<endl;
}
