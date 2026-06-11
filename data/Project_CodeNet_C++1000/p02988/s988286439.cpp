#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, s = 0;
  cin >> n;
  vector<int> v(n);
  for(int i = 0;i < n;i++) cin >> v[i];
  for(int i = 0;i < n-2;i++) {
    if((v[i] - v[i+1])*(v[i+1] - v[i+2]) > 0) s++;
  }
  cout << s << endl;
}