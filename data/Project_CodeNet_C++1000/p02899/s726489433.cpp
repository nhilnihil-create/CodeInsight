#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i);
    b.at(a.at(i)-1)=i+1;
  }
  for(int i=0;i<n;i++){
    cout << b.at(i) << ' ';
  }
  cout << endl;
}

