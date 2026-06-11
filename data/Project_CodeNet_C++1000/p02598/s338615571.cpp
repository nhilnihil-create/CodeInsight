#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>


using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair
#define mt make_tuple

vector<int> a;

int binary_search(int K){
  int l = 0;
  int r = 1e9+1;
  while(r - l > 1){
    int cnt = 0;
    int mid = (r + l) / 2;
    for(const auto& e: a){
      if(e > mid){cnt += (e-1) / mid;}
    }
    if(cnt <= K){r = mid;}
    if(cnt > K){l = mid;}
  }
  /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
  return r;
}

int main(void)
{
  int N, K;
  cin >> N >> K;
  for(int i=0;i<N;i++){
    int in;
    cin >> in;
    a.push_back(in);
  }
  cout << binary_search(K) << endl;
  return 0;
}
