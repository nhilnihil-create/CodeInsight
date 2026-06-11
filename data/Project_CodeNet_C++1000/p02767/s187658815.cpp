#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>vec(N);
  vector<long long>ans;
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  sort(vec.begin(), vec.end()); 
  for(int j=vec.at(0);j<=vec.at(N-1);j++){
    int X=0;
    for(int k=0; k < N; k++){
      X += (vec.at(k)-j)*(vec.at(k)-j);
    }
    ans.push_back(X);
  }
  sort(ans.begin(), ans.end());
  cout << ans.at(0) << endl;
}
