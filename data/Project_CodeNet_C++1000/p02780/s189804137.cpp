#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  ll N,K;
  cin >> N >> K;
  ll p[N];
  for(int i=0;i<N;i++){
    cin >> p[i];
  }
  ll sum[200001];
  sum[0]=0;
  for(int i=1;i<200001;i++){
    sum[i] = sum[i-1]+i;
  }
  vector<pair<ll ,int> >sum2(N-K+1);
  ll go=0;
  for(int j=0;j<K;j++){
    go+=p[j];
  }
  sum2[0] = make_pair(go,0);
  for(int i=1;i<N-K+1;i++){
    sum2[i]=make_pair(sum2[i-1].first-p[i-1]+p[i+K-1],i);
  }
  sort(sum2.begin(),sum2.end());
  double ans=0;
  for(ll i=0;i<K;i++){
    ans += sum[p[sum2[N-K].second+i]]/(1.0*p[sum2[N-K].second+i]);
  }
  printf("%.12f\n", ans);

}
