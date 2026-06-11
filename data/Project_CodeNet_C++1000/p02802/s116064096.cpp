#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG

int main() {
  
  ll N, M;
  cin >> N >> M;
  
  vector<bool> ac(N + 1);
  vector<int> wa(N + 1);
  
  for (ll i=0; i<M;i++){
    ll problrem_id;
    string result;
    cin >> problrem_id >> result;
    if(result == "AC"){
      ac[problrem_id]=1;
    }
    if(result == "WA" && ac[problrem_id] == 0){
      wa[problrem_id]++;
    }
  }

  ll count_ac = 0;
  ll count_wa = 0;
  for(ll i=0; i<N + 1; i++){
    if(ac[i]){
      count_ac++;
      count_wa += wa[i];
    }
  }
  
  cout << count_ac << " " << count_wa << endl;

  return 0;
}
