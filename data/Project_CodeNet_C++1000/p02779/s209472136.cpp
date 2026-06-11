#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a.at(i);
  sort(a.begin(), a.end());
  for(int i=0;i<a.size()-1;i++){
    if(a.at(i)==a.at(i+1)){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}