#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<string> wea = {"Sunny", "Cloudy", "Rainy"};
  string s;cin >> s;
  
  for(int i=0; i<3; i++){
    if(s.size()==wea[i].size() && s==wea[i]){
      cout << wea[(i+1)%3] << endl;
      break;
    }
  }
  return 0;
}