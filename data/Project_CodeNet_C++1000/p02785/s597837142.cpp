#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n, k;
  cin >> n >> k; //n体 k = 必殺技の回数
  
  vector<int> vec(n);
  
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    vec.at(i) = x;
  }
  
  sort(vec.begin(), vec.end());
  long long total = 0;
  int p = 0;
  
  if(vec.size() > k){
    for(int i = vec.size(); i > k; i--){
      total += vec.at(p);
      p++;
    }
  }
  
  cout << total << endl;
  
  
  
  
}