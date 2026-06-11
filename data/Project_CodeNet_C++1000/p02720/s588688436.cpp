#include<bits/stdc++.h>
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

#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using P = pair<long long, long long>;

int main() {
  long long K;
  cin >> K;
  long long cnt = 0;
  queue<string> que;
  rep(i, 9) {
    que.push(to_string(i+1));
    cnt++;
    if(cnt == K) {
      cout << i+1 << endl;
      return 0;
    }
  }

  while(que.size()) {
    string p = que.front();
    que.pop();
    char last = p[p.size()-1];
    string temp;
      if(last != '0') {
          temp = p + to_string(last - '0' - 1);
          que.push(temp);
          cnt++;
          if(cnt == K) {
            cout << temp << endl;
            return 0;
          }
      }
        temp = p + to_string(last - '0');
        que.push(temp);
        cnt++;
        if(cnt == K) {
          cout << temp << endl;
          return 0;
        }
      if(last != '9') {
        temp = p + to_string(last - '0' + 1);
        que.push(temp);
        cnt++;
        if(cnt == K) {
          cout << temp << endl;
          return 0;
        }
      }
  }

  return 0;
}