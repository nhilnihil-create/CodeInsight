#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> p(n);
  
  for(int i = 0; i < n; i++){
    cin >> p.at(i);
  }
  
  int ans = 0;
  
  for(int i = 0; i < n; i++){
    if(p.at(i)!=(i+1)){
      ans++;
    }
  }
  
  if(ans<=2){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
  
}