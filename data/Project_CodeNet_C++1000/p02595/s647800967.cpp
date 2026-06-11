#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,D;
  cin >> N >> D;
 
  vector<vector<long long>> k(N,vector<long long>(2));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2; j++){
     cin >> k.at(i).at(j);
}
}
  
  int a = 0;
  
  for(int i = 0; i < N; i++){
    if(k.at(i).at(0)*k.at(i).at(0) + k.at(i).at(1)*k.at(i).at(1) <= D*D)
    {a++;}
  }
  
  cout << a << endl;
}
       