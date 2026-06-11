#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h;
  while(cin>>h,h) {
    int in[h][5];
    FOR(i,0,h) {
      FOR(j,0,5) {
        cin >> in[i][j];
      }
    }
    vector<queue<int> > Q(5);
    for(int i = h - 1; i >= 0; i--) {
      FOR(j,0,5) {
        Q[j].push(in[i][j]);
      }
    }
    // ?¶??????????0
    bool end = true;
    int ans = 0;
    FOR(x,0,6) {
      // ?¶?????????????0
      int num[h][5];
      FOR(i,0,h) {
        FOR(j,0,5) {
          num[i][j] = Q[j].empty() ? 0 : Q[j].front();
          if(!Q[j].empty()) Q[j].pop();
        }
      }
      FOR(i,0,h) {
        int cnt = 1;
        FOR(j,0,4) {
          if(num[i][j] != 0 && num[i][j] == num[i][j+1]) cnt++;
          else {
            if(cnt >= 3) {
              end = false;
              int k = j;
              while(cnt--) {
                ans += num[i][k];
                num[i][k] = 0;
                k--;
              }
            }
            cnt = 1;
          }
        }
        if(cnt >= 3) {
          end = false;
          int k = 4;
          while(cnt--) {
            ans += num[i][k];
            num[i][k] = 0;
            k--;
          }
        }
      }
      if(end) break;
      // ????????????
      FOR(i,0,h) FOR(j,0,5) {
        if(num[i][j] != 0) Q[j].push(num[i][j]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}