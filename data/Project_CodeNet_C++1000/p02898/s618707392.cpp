#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;
  
  int count = 0;
  
  vector<int> H(N);
  for(int i=0;i<N;i++){
    cin >> H.at(i);
    if(H.at(i)>=K){count++;}
  }
  
  cout << count<< endl;
  
}