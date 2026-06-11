#include<iostream>
#include<string>
using namespace std;
int main(){
  int s = 0;
  string a, b;
  cin >> a >> b;
  for(int i = 0; i < 3; i++){
    if(a[i] == b[i]){
      s++;
    }
  }
  cout << s << "\n";
}