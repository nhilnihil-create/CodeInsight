#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> h(n);
  int ans = 0, count = 0;
  for(int i = 0; i < n; i++){
    cin >> h[i];
  }
  for(int i = 0; i < n - 1; i++){
    if(h[i] >= h[i + 1]) count++;
    else{
      ans = max(ans, count);
      count = 0;
    }
  }
  cout << max(ans, count) << endl;
}