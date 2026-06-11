#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  vector<string> S(N);
  
  map<string,ll> sums;
  
  for(int i=0; i<N; i++){
    cin >> S[i];
    sort(S[i].begin(), S[i].end());
    
    if(sums.count(S[i])==0){
      sums[S[i]] = 1;
    }else{
      sums[S[i]]++;
    }
  }
 
  ll ans = 0;
  
  for(auto itr=sums.begin(); itr != sums.end(); ++itr){
    if(itr->second > 1) {
             ll num = itr->second-1;
             ans += (num*(num+1)/2);
     }
  }
  
  cout << ans << endl;

  return 0;
}