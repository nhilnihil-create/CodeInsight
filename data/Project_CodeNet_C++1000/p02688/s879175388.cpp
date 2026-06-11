#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k; cin >> n >> k;
  set<int>s;
  for(int i = 0; i < n; i++){
    int d; cin>> d;
    for(int j = 0; j < d; j++){
      int a; cin >> a;
      s.insert(a);
    }
  }
  cout << n - s.size();
}