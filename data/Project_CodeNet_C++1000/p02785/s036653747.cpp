#include <bits/stdc++.h>
using namespace std;

int main(){
  long int N,K;
  cin >> N >> K;
  vector<int> h(N);
  for(int i=0;i<N;i++){
    cin >> h.at(i);
  }
  sort(h.begin(),h.end());
  long int ans =0;
  for(int i=0;i<N-K;i++) ans+=h.at(i);
  cout << ans << endl;
}