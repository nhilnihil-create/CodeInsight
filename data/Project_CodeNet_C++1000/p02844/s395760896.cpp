#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<queue>
#include<numeric>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
  int n;
  string s;
  cin >> n >> s;

  int count = 0;
  vector<int> zumi(10, 0); // 1はずみ
  vector<int> zumi2(10, 0);
  for (int i = n-1; i >= 0; i--) {
    if (zumi[s[i] - '0']) {
      continue;
    } else {
      zumi[s[i] - '0'] = 1;
    }
    vector<int> zumi1(10, 0);
    for (int j = i-1; j >= 0; j--) {
      if (zumi1[s[j] - '0']) {
        continue;
      } else {
        zumi1[s[j] - '0'] = 1;
      }
      vector<int> zumi2(10, 0);
      for (int k = j-1; k >= 0; k--) {
        if (zumi2[s[k] - '0']) {
          continue;
        } else {
          zumi2[s[k] - '0'] = 1;
          count++;
        }
      }
    }
  }
  cout << count << endl;
}  
