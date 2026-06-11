#include<iostream>
#include<set>
using namespace std;
int main(){
  string s; cin >> s;
  set<char>a;
  for(int i = 0; i < 4; i++){
    a.insert(s.at(i));
  }
  if(a.size() == 2)
    cout << "Yes";
  else
    cout << "No";
}