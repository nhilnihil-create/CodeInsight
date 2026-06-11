#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void){
  map<string, int> mp;
  int n;
  
  cin >> n;
  for (int i=0; i<n; i++){
    string s; cin >> s;
    mp.insert(make_pair(s,0));
  }
  cout << (mp.size()) << endl;
  return 0;
}