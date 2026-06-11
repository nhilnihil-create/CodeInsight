#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  vector<int> a(n+1),b(n+1);
  for(int i = 1; i <= n; i++){
    cin >> a.at(i);
    b.at(a.at(i)) += 1;
  }
  
  for(int i = 1; i <= n; i++){
    cout << b.at(i) << endl;
  }
  
}