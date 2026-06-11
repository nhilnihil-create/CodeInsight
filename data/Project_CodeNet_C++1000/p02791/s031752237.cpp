#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> P(N);
  int min=N+1;
  int ans=0;
  
  for(int i=0; i<N; i++){
    cin>>P.at(i);
    if(P.at(i)<min){
      ans++;
      min=P.at(i);
    }
  }
  cout << ans << endl;
}