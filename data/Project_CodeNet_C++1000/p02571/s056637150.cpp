#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
    
  cin >> s;
  cin >> t;
  
  int minCount = t.size();
  
  for(unsigned int i = 0; i < s.size()-t.size()+1; i++){
    int count = 0;
    for(unsigned int j = 0; j < t.size(); j++){
      if(s.at(i+j) != t.at(j)){
      	count++;
      }
    }
    if(count < minCount){
      minCount = count;
    }
  }

  cout << minCount << endl;
}
