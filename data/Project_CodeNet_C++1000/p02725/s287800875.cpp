#include<bits/stdc++.h>
using namespace std;
int main() {
  int k, n; cin >> k >> n;
  vector<int> a(n);
  for(int &c : a) {
    cin >> c;
  }
  vector<int> dist(n);
  int longest = 0;
  for(int i = 0; i < n-1; i++) {
    dist.at(i) = a.at(i+1)-a.at(i);
    if(dist.at(i) > longest) {
      longest = dist.at(i);
    }
  }
  dist.at(n-1) = a.at(0) + k - a.at(n-1);
  if(dist.at(n-1) > longest) {
    longest = dist.at(n-1);
  }
  cout << k - longest << endl;
}