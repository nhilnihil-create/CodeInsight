#include <iostream>
#include <vector>
using namespace std;
int main(){
  string s;
  cin >> s;
  vector<string> v({"SUN","MON","TUE","WED","THU","FRI","SAT"});
  int i;
  for(i=0;i<7;i++){
    if(v[i]==s){
      cout << 7-i << "\n";
      return 0;
    }
  }
}