#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<vector<int>> vec(N,vector<int>(2));
  for(int i=0; i<N; i++){
    for(int j=0; j<2; j++){
      cin >> vec.at(i).at(j);
    }
  }
  
  map<pair<int,int>,int> mp;
  pair<int,int> P;
  pair<int,int> Q;
  for(int i=0; i<N-1; i++){
    int px = vec.at(i).at(0);
    int py = vec.at(i).at(1);
    for(int j=i+1; j<N; j++){
      int qx = vec.at(j).at(0);
      int qy = vec.at(j).at(1);
      P = make_pair(px-qx,py-qy);
      Q = make_pair(qx-px,qy-py);
      if(mp.count(P)){
        mp[P]++;
      }
      else{
        mp[P] = 1;
      }
      if(mp.count(Q)){
        mp[Q]++;
      }
      else{
        mp[Q] = 1;
      }
    }
  }
  
  int max_mp = 0;
  for(auto itr = mp.begin(); itr != mp.end(); itr++){
    int x = itr->second;
    max_mp = max(max_mp,x);
  }
  cout << N - max_mp << endl;
}   