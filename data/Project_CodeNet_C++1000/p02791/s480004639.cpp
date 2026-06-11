#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> P(N);
  
  int min = 1000000;
  int count=0;
  
  for(int i=0;i<N;i++){
    cin >> P.at(i);
    
    if(min>P.at(i)){
      count++;
      min = P.at(i);
    }
  }
  
  cout << count << endl;  
}