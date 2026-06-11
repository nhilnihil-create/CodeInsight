#include <iostream>
#include <string>
using namespace std;
int main(){
  int n;
  string s;
  cin >> n >> s;
  int i;
  int cnt = 0;
  for(i=0;i<n-2;i++){
    if(s.substr(i,3)=="ABC") cnt++;
  }
  cout << cnt << "\n";
  return 0;
}