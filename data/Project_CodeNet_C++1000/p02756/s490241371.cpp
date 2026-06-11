#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

char a[500000];
deque<char> que;

int main() {
  string s;
  cin >> s;
  rep(i, s.size()) {
    que.push_back(s[i]);
  }
  bool f = true;
  int Q;
  cin >> Q;
  rep(i, Q) {
    int temp;
    cin >> temp;
    if(temp == 1) {
      f ^= 1;
    } else {
      int tempf;
      char c;
      cin >> tempf >> c;
        if(f ^ (tempf - 1)) {
          que.push_front(c);
        } else {
          que.push_back(c);
        }
    }
  }
  if(f) {
    while(que.size()) {
      cout << que.front();
      que.pop_front();
    }
    cout << endl;
  } else {
    while(que.size()) {
      cout << que.back();
      que.pop_back();
    }
    cout << endl;
  }
  return 0;
}