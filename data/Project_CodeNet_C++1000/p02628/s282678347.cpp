#include <bits/stdc++.h>
using namespace std; 

int main(){
  int N,K,sum=0;
  cin >> N >> K;
  vector<int> P(N);
  for(int i=0;i<N;i++){
    cin >> P.at(i);
  }
  sort(P.begin(),P.end());
  for(int i=0;i<K;i++){
    sum+=P.at(i);
  }
  cout << sum << endl;
}
  