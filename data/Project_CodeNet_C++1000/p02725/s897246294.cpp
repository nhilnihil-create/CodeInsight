#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int K,N;
  cin>>K>>N;
  
  vector<int> dis(N);
  for(int i=0; i<N; i++){
    cin>>dis.at(i);
  }
  vector<int> w(N);
  for(int i=0; i<N; i++){
    if (i==N-1) {
      w.at(i) = K+dis.at(0)-dis.at(i);
    }
    else {
      w.at(i) = dis.at(i+1) - dis.at(i);
    }
  }
  sort(w.begin(), w.end());
  int ans = K-w.at(N-1);
  cout<<ans<<"\n";
}