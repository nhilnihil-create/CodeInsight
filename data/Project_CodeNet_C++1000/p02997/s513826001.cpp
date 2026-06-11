#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
5 6
  2
  |
5-1-3
  |
  4

5 3
1-2-3-4-5
1-2
 -3
 -4
 -5
 -6...をつくっておいて、Kによって辺を増やしていくとか？
(n-1)C2通り
毎回最短検索するとして
100^3*100
1本ふやせば1通りへるっぽい
*/
int main(){
  ll N,K; cin>>N>>K;
  ll high=((N-1)*(N-2))/2;
  if(K>high){
    cout<<-1<<endl;
    return 0;
  }
  vector<pair<ll,ll>> ans(0,make_pair(0,0));
  //最初に線入れ
  for(ll i=2; i<=N; i++) ans.emplace_back(1,i);
  ll i=2, j=3;
  while(K<high){
    if(j>N){
      i++;
      j=i+1;
    }
    ans.emplace_back(i,j);
    j++;
    high--;
  }
  ll asz=ans.size();
  cout<<asz<<endl;
  for(ll i=0; i<asz; i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
}