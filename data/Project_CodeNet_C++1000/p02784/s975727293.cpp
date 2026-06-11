#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, N;
  cin >> H >> N;
  
  int x = 0;
  
  vector<int> kougeki(N);
  for(int i=0; i<N ;i++){
    cin >> kougeki.at(i);
    
    x = x + kougeki.at(i);
  }
  
  if(x>=H){
   cout << "Yes" << endl;
 }
  else {
    cout << "No" << endl;
  }
 
  
}

