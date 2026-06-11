#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main() {
  char buf[120];
  while (true) {
    fgets(buf, 120, stdin);
    if (buf[strlen(buf)-1] == '\n') buf[strlen(buf)-1] = '\0';
    if (buf[0] == '.' && buf[1] == '\0') break;
    string s = "";
    for (int i=0;buf[i]!='\0';i++) {
      if (buf[i] == '(' || buf[i] == ')'
        || buf[i] == '[' || buf[i] == ']') {
        s += buf[i];
      }
    }
    //printf("%s\n", s.c_str());
    bool yes = true;
    while (!s.empty()) {
      int n = s.find("()");
      if (n == string::npos) {
        n = s.find("[]");
        if (n == string::npos) {
          yes = false;
          break;
        }
      }
      s.erase(n, 2);
    }
    puts(yes ? "yes" : "no");
  }
  return 0;
}