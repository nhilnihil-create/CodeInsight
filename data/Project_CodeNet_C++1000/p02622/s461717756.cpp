#include<iostream>
#include<string>
using namespace std;
int main(){
  string s, t;
  cin >> s >> t;
  int n = s.size(), sm = 0;
  for(int i = 0; i < n; i++){
    if(s[i] != t[i]){
      sm++;
    }
  }
  
  cout << sm << "\n";
}