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

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

int main() {
  int N, K, C;
  string S;
  cin >> N >> K >> C;
  cin >> S;
  vector<int> vv;
  int p = S.size() - 1;
  int count = 0;
  while(p >= 0) {
    if(S[p] == 'o') {
      vv.push_back(p);
      count++;
      if(count == K) break;
      p = p - C - 1;
      continue;
    }
    p--;
  }

  vector<int> v;
  rep(i, vv.size()) {
    v.push_back(vv[vv.size()-1-i]);
  }

  // vector<int> v2;
  // int ind = 0;
  // count = 0;
  // while(ind < S.size()) {
  //   if(S[ind] == 'o') {
  //     v2.push_back(ind);
  //     count++;
  //     if(count == K) break;
  //     ind -= 4;
  //     continue;
  //   }
  //   ind--;
  // }

  // rep(i, K) {
  //   if(v[i] == v2[i]) {
  //     cout << i+1 << endl;
  //   }
  // }

  v.push_back(0);


  int start = 0;
  int end = v[0];
  int cnt = 0;
  int ns = 0;
  int ne = v[0];
  do {
    start = ns;
    end = ne;
    bool f = false;
    for(int i = start; i < end; i++) {
      if(S[i] == 'o') {
        cnt++;
        ns = i + C + 1;
        ne = v[cnt];
        f = true;
        break;
      }
    }
    if(!f) {
      cout << end + 1 << endl;
      cnt++;
      ns = end + C + 1;
      ne = v[cnt];
    }
  } while(cnt < v.size()-1);
  return 0;
}