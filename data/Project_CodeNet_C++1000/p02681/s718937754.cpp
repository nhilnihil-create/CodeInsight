#include<iostream>
#include<string>
using namespace std;
int main(){
  int a, b;
  string s, z;
  cin >> s >> z;
  a = s.size();
  b = z.size();
  for(int i = 0; i < a; i++){
    if(s[i] != z[i]){
      cout << "No\n";
      break;
    }
    if(i == a - 1 && a == b - 1){
      cout << "Yes\n";
    }
  }
}