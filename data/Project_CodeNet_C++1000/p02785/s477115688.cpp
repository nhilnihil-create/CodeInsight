#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,k;
  cin >> n >> k;
  vector<int> H(n);
  for (int i = 0; i < n; i++){
    cin >> H[i];
  }
  sort(H.begin(), H.end());
  long long sum = 0;
  if (n <= k){
    cout << "0" << endl;
  }else{
    for (int i = 0; i < n-k; i++){
      sum += H[i];
    }
    cout << sum << endl;
  }
}