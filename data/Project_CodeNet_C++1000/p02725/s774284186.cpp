#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, N;
  cin >> K >> N;
  
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  
  
  vector<int> sa(N-1);
  int saidai = 0;
  for(int i=0;i<N-1;i++){
    sa.at(i) = A.at(i+1)-A.at(i);
    if(sa.at(i)>saidai){ saidai=sa.at(i);}
  }
  
  int sa0=0;
  sa0 = A.at(0) + K-A.at(N-1);
  
  if(sa0>saidai){ saidai=sa0;}
  
  cout << K-saidai << endl;
  
  
}