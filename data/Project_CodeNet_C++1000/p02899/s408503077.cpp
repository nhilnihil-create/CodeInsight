#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int,int>> p(n);
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    p.at(i) = make_pair(a,i);
  }
  sort(p.begin(),p.end());
  for(int j=0;j<n;j++){
    int a,b;
    tie(a,b) = p.at(j);
    cout << b+1 << " " ;
  }
}