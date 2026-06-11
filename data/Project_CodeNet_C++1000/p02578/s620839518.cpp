#include<bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n, 0);
  for(int i = 0; i < n; ++i){
    cin >> v[i];
  }
  long long sum = 0;
  int now = v[0];
  for(int i = 1; i < n; ++i){
    if(now > v[i]){
      sum += now - v[i];
    }
    else {
      now = v[i];
    }
  }
  cout << sum << endl;
}