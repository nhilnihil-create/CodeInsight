#include <iostream>
using namespace std;


int main(){
  string s; cin >> s;
  cout << (s += (s.back() == 's' ? "es" : "s")) << endl;
}