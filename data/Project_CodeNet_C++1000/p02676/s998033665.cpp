#include <iostream>
#include <string>
using namespace std;
int main(){
  int k;
  string s;
  cin >> k;
  cin >> s;
  if((int)s.size() <= k){
    cout << s;
  }else{
    string ns="";
    for(int i=0;i<k;i++){
      ns += s[i];
    }
    ns += "...";
    cout << ns;
  }
}
    