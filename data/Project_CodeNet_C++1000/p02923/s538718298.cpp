#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);

  for(int i = 0; i < n; i++){
    cin >> h[i];
  }

  int mx = 0;
  int temp = 0;
  for(int i = 0; i < n-1; i++){
    if(h[i] >= h[i+1]){
      temp++;
      mx = max(mx, temp);
    }
    else{
      temp = 0;
    }
  }

  cout << mx << endl;

  return 0;

}