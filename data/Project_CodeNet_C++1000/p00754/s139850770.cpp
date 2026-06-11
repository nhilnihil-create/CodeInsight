#include <algorithm>
#include <vector>
#include <cfloat>
#include <string>
#include <cmath>
#include <set>
#include <cstdlib>
#include <map>
#include <ctime>
#include <iomanip>
#include <functional>
#include <deque>
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#include <stack>
#include <climits>
#include <sys/time.h>
#include <cctype>

using namespace std;

typedef long long ll;

#define MARU 0
#define KAKU 1

int check(char c) {
  if (c == '(' ||
      c == ')') {
    return MARU;
  }
  if (c == '[' ||
      c == ']' ) {
    return KAKU;
  }
  return -1;
}

int main() {
  string str;
  while(true) {
    getline(cin, str);
    if (str == ".") break;

    string tstr;
    for (int i = 0; i < str.size(); i++) {
      if (check(str[i]) != -1) {
	tstr += str[i];
      }
    }

    if (tstr.size() == 0) {
      std::cout << "yes" << std::endl;
      continue;
    }
    if (tstr[0] == ')' ||
	tstr[0] == ']') {
      std::cout << "no" << std::endl;
      continue;
    }

    // std::cout << tstr << std::endl;
    bool yes = true;
    stack <int> st;
    st.push(check(tstr[0]));
    for (int i = 1; i < tstr.size(); i++) {
      if (st.size()) {
	int val = st.top();
	if (tstr[i] == '(' ||
	    tstr[i] == '[') {
	  st.push(check(tstr[i]));
	}else {
	  if (val != check(tstr[i])) {
	    yes = false;
	    break;
	  }else {
	    st.pop();
	  }
	}
      }else {
	if (tstr[i] == ')' ||
	    tstr[i] == ']') {
	  yes = false;
	  break;
	}else {
	  st.push(check(tstr[i]));
	}
      }
    }

    if (yes && st.empty()) {
      std::cout << "yes" << std::endl;
    }else {
      std::cout << "no" << std::endl;
    }
  }
}