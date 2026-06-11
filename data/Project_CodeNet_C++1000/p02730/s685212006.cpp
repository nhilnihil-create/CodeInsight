#include <iostream>
#include <string>
using namespace std;
int main(){
  
  string s; cin >> s;
  string a,b;
  for(int i = 0; i < s.size(); i++){
    if(i < s.size() / 2){
    a.push_back(s[i]);
    }
    if(i > s.size()/ 2){
    b.push_back(s[i]);
    }
  }
  
  
  for(int i = 0; i < s.size() / 2; i++){
  if(s[i] != s[s.size() - i - 1]){
    cout << "No" << endl; return 0;
  }
  }
  for(int i = 0; i < a.size() / 2; i++){
  if(a[i] != a[a.size() - i - 1]){
    cout << "No" << endl; return 0;
  }
  }
  for(int i = 0; i < b.size() / 2; i++){
  if(b[i] != b[b.size() - i - 1]) {
    cout << "No" << endl; return 0;
  }
  }
    cout << "Yes" << endl;

    return 0;
}