#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main(){
  int N;
  cin >> N;
  vector<int> L(N);
  rep(i,N){
    cin >> L.at(i);
  }
  sort(L.begin(), L.end());
  int ans = 0;
  for(int i=0; i<N-2; i++){
    for(int j=i+1; j<N-1; j++){
      if(L.at(i)==L.at(j)) continue;
      for(int k=j+1; k<N; k++){
        if(L.at(j)==L.at(k)) continue;
        if(L.at(k)<L.at(i)+L.at(j)) ans++;
      }
    }
  }
  cout << ans;
  return 0;
}