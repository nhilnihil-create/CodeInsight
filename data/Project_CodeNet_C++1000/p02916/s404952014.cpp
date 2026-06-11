#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);
  
  long long sum = 0;
  
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
  }
  
  for(int i = 0; i < n; i++){
    cin >> b.at(i);
    sum += b.at(i);
  }
  
  for(int i = 0; i < n; i++){
    cin >> c.at(i);
  }
  
  for(int i = 0; i < n-1; i++){
    if(a.at(i+1)==a.at(i)+1){
      sum += c.at(a.at(i)-1);
    }
  }
  
  cout << sum << endl;
}