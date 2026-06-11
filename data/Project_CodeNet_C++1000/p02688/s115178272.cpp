#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n, k;
  cin >> n >> k;
  
  vector<bool> s(n, false);
  
  for(int i = 0; i < k; i++){
    int d;
    cin >> d;
    vector<int> a(d);
    for(int j = 0; j < d; j++) cin >> a.at(j);
      
    for(int j = 0; j < d; j++){
      s.at(a.at(j) - 1) = true;
    }
  }
  
  int count = 0;
  for(int i = 0; i < n; i++){
    if(s.at(i) == false) count++;
  }
  cout << count << endl;
}