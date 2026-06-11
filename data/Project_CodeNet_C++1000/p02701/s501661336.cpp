#include <iostream>
#include <set>
using namespace std;

int main() {
  int n;
  cin >> n;
  string temp;
  set<string> st;
  for(int i=0; i < n; i++)
  {
    cin >> temp;
    st.insert(temp);
  }
  cout << st.size();
  return 0;
}