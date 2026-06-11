#include <bits/stdc++.h>
using namespace std;

int main(){
  constexpr int Ndig= 10;
  int N;
  string S;
  cin >> N >> S;

  vector<vector<int>> positions(Ndig);
  for(int i=0; i<N; i++){
    int d= stoi(S.substr(i,1));
    positions.at(d).emplace_back(i);
  }

  vector<int> existdig;
  for(int d=0; d<Ndig; d++){
    if(!positions.at(d).empty()){
      existdig.emplace_back(d);
    }
  }

  int ans= 0;
  for(auto head:existdig){
    for(auto tail:existdig){
      int pos_head= positions.at(head).at(0);
      int pos_tail= positions.at(tail).back();
      if(pos_head < pos_tail){
        for(auto mid:existdig){
          auto itr0= upper_bound(positions.at(mid).begin(), positions.at(mid).end(), pos_head);
          auto itr1= lower_bound(positions.at(mid).begin(), positions.at(mid).end(), pos_tail)- 1;
          
          if(distance(itr0, itr1) >= 0){
            ans++;
          }
        }
      }
    }
  }

  cout << ans << endl;
}