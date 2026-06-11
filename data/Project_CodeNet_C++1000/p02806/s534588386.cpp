#include<bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >> n;
  
  vector<pair<string, int> > v(n);
  for(auto &it : v) cin >> it.first >> it.second;
  
  string x; cin >> x;
  bool ok = false;
  int sum = 0;
  
  for(auto it : v){
     if(ok){
       sum += it.second;
     }
     if(it.first == x) ok = true;
  }
  
  cout << sum;
  return 0;
}
