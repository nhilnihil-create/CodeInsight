#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N, M, V, P;
  cin >> N >> M >> V >> P;
  vector<int64_t> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  sort(vec.rbegin(),vec.rend());
  int border = vec.at(P-1); //border以上であれば可能
  int ok = P-1;
  int ng = N;
  while(ng - ok > 1){
    bool flag = true;
    int mid = (ok + ng) / 2;
    int score = vec.at(mid) + M;
    if(score < border){
      flag = false;
    }
    int64_t vote = V*M;
    for(int i=0; i<N; i++){
      if(i < P-1 || i >= mid){
        vote -= M;
      }
      else{
        vote -= max((int64_t)0,score - vec.at(i));
      }
    }
    if(vote > 0){
      flag = false;
    }
    if(flag){
      ok = mid;
    }
    else{
      ng = mid;
    }
  }
  cout << ok + 1 << endl;  
}