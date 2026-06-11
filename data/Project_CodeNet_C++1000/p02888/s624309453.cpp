#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n)for(int i=0; i<n; i++)

int main(){
  int N;
  cin >> N;
  vector<int> L(N);
  rep(i, N)
    cin >> L[i];
  //

  sort(L.begin(), L.end());

  long long ans = 0;
  for(int i=0; i<N-2; i++){
    for(int j=i+1; j<N-1; j++){
      int sum = L[i] + L[j];
      int right = upper_bound(L.begin()+j, L.end(), sum-1) - L.begin();
      ans += (right-1 - j);
    }
  }
  
  cout << ans << endl;

  return 0;
}
