#include <bits/stdc++.h>
using namespace std;

int main(){
  constexpr int Nbit= 1e5;
  int N,M;
  cin >> N >> M;

  bitset<Nbit> ACs;
  vector<int> WAs(N);

  int prob; string status;
  for(int i=0; i<M; i++){
    cin >> prob >> status;
    prob--; // 1-indexed -> 0-indexed
    if(status=="AC"){
      ACs.set(prob);
    }
    else if(!ACs.test(prob)){
      WAs.at(prob)++;
    }
  }

  int penalty= 0;
  for(int i=0; i<N; i++){
    if(ACs.test(i)){
      penalty+= WAs.at(i);
    }
  }
  
  cout << ACs.count() <<" "<< penalty << endl;
}