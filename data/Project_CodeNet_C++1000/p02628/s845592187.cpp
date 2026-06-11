#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int k;
  cin >> n >> k;
  vector<int> v(n);
  int tmp;
  for (int i = 0; i < n; i++){
    cin >> v.at(i);
  }
  sort(v.begin(),v.end());
  int b=0;
  for (int i = 0; i < k; i++){
    b=b+v.at(i);
  }
  cout << b << endl;
}
