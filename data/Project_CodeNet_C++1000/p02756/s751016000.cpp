#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>

int N = 100000;

using namespace std;
int main(){
  string s;
  int q;
  vector<int> t(N), f(N);
  vector<string> c(N);
  cin >> s >> q;
  t.resize(q), f.resize(q), c.resize(q);
  for(int i = 0; i < q; i++){
    cin >> t[i];
    if(t[i] == 2){
      cin >> f[i] >> c[i];
    }
  }

  bool back = false;
  for(int i = 0; i < q; i++) {
    if(t[i] == 1) {
      back = !back;
    } else {
      if(back == f[i]-1) {
        s = c[i] + s;
      } else {
        s = s + c[i];
      }
    }
  }

  if(back) {
    reverse(s.begin(), s.end());
  }
  cout << s << endl;

  return 0;
}
