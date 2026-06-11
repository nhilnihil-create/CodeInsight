#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int k;
    string s, r;
    cin >> k;
    cin >> s;

    if(s.length() <= k) {
      cout << s;
    } else {
      r = s.substr(0,k).append("...");
      cout << r;
    }
    return 0;
}