#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(int argc, char *argv[])
{
  for(;;) {
    string str;
    getline(cin, str);
    int l = str.length();
    if(l == 1) break;
    auto check = [l, &str]() {
      vector<char> st;
      for(int i = 0; i < l; i++) {
        char c = str[i];
        if(c == '(' || c == '[') {
          st.push_back(c);
        } else if(c == ')') {
          if(st.size() == 0) return false;
          if(st.back() == '(') {
            st.pop_back();
          } else {
            return false;
          }
        } else if(c == ']') {
          if(st.size() == 0) return false;
          if(st.back() == '[') {
            st.pop_back();
          } else {
            return false;
          }
        }
      }
      return st.size() == 0;
    };
    cout << (check() ? "yes" : "no") << endl;
  }
  return 0;
}