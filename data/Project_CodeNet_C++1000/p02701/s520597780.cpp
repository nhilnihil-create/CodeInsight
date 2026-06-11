#include <iostream>
#include <string>
#include <set>

using namespace	std;

int main() {
  set<string> data;
  int N; cin>>N;
  while(--N >= 0) {
    string s; cin>>s;
    data.insert(s);
  }
  cout << data.size() << endl;
  return 0;
}
