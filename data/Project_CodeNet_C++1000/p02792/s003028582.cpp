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

int main() {
  int key = 1;
  int a[7];
  rep(i, 7) {
    a[i] = key;
    key *= 10;
  }
  int N;
  cin >> N;
  string n = to_string(N);
  int cnt = n.size();
  if(cnt == 1) {
    cout << N << endl;
    return 0;
  }
  int ans = 0;
  for(int i = 1; i <= N; i++) {
    string s = to_string(i);
    char top = s[0];
    char bot = s[s.size()-1];
    int t = 2;
    if(bot == '0') continue;
    if(top == bot) {
      t = 1;
    }
    while(t <= cnt) {
      if(t == cnt) {
        if(bot == n[0]) {
          if(cnt >= 3) {
            rep(i, cnt-2) {
              ans += (n[i+1] - '0') * a[cnt-i-3];
            }
          }
          if(top <= n[n.size()-1]) {
            ans += 1;
          }
        } else if(bot < n[0]) {
          ans += a[t-2];
        }

      } else {
        if(t == 1) {
          ans += 1;
        } else {
          ans += a[t-2];
        }
      }
      t++;
    }
    // cout << i << " " << ans << endl;
  }
  cout << ans << endl;
  return 0;
}