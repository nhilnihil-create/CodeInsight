#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main(){
  vector<string> st;
  int N;
  string str;
  while(cin >> str && str != "-"){
    cin >> N;
    for(int i=0;i<N;i++){
      int h;
      string s1, s2;
      cin >> h;
      s1 = str.substr(0, h);
      s2 = str.substr(h, str.size()-h);
      str = s2 + s1;
    }
    st.push_back(str);
  }

  for(int i=0;i<st.size();i++){
    cout << st[i] << endl;
  }
  return 0;
}