#include <bits/stdc++.h>
using namespace std;

int main() {
  int K,N;
  cin >> K >> N;
  vector<int>vec(N),aida(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  for(int i=0; i<N-1; i++){
    aida[i] = vec[i+1]-vec[i];
  }
  aida[N-1] = vec[0]+K-vec[N-1];
  sort(aida.begin(),aida.end());
  cout << K-aida[N-1] << endl;
}
