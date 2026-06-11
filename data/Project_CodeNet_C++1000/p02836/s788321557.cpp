#include <iostream>
using namespace std;

int main() {
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++){
    cin >> s.at(i);
  }
  int a=0;
  for(int i=0;i<s.size()/2;i++){
    if(s.at(i)!=s.at(s.size()-1-i)){
      a++;
    }
  }
       cout << a << endl;
}
       