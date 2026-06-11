#include <bits/stdc++.h>
using namespace std;
int main() {
  string s; cin >> s;
  string ans;
  vector<string> wez = vector<string>{"Sunny","Cloudy","Rainy"};
  for(int i=0; i<3; i++){
    if(wez[i] == s){
      if(i==2) ans = wez[0];
      else ans = wez[i+1];
    }
  }
  cout << ans << endl;
}