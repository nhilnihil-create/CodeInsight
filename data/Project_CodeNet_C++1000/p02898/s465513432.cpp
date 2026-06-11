#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K,count=0;
  cin >> N >> K;
  vector<int> H(N);
  
  for(int i=0; i<N; i++) {
    cin >> H[i];
    if(H[i]>=K) count++;
  }
  cout << count << endl;
}