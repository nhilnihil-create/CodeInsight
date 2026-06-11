#include <iostream>

using namespace std;

string st;

int main() {

  int n, s = 1e9, m = 0, l = 0;
  cin >> st;
  int j = st.size() - 1;
  for(int i = 0;i < st.size() / 2;i++){
    if(st[i] != st[j]){
      l++;
    }
    j--;
  }
  cout << l;
  return 0;
}
