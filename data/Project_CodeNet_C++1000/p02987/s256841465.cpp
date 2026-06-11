#include<iostream>
#include<string>
using namespace std;
int main(){
  string s;
  cin >> s;
  int p, f = 0, a;
  a = s.size();
  char k = s[0];
  char r = s[2];
  for(int i = 1; i < a; i++){
    if(k == s[i]){
      break;
    }
    if(k != s[i]){
      r = s[i];
    }
    if(i == 3){
      cout << "No\n";
      return 0;
    }
  }
  if(k == r){
    cout << "No\n";
    return 0;
  }
  for(int i = 1; i < a; i++){
    if(r == s[i]){
      f++;
    }
    if(f == 2){
      break;
    }
    if(i == 3){
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}
  