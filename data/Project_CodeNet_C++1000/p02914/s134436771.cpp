#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010


int main(){
  int N;
  ll a[SIZE], b[SIZE] = {}, sum = 0;

  scanf("%d", &N);

  for(int i=0; i<N; i++) {
    scanf("%lld", a+i);
    b[i] = a[i];
    sum ^= a[i];
  }

  N = max(N, 61);


  for(int i=0; i<=60; i++) {
    if(sum & (1LL << i)) {
      b[N++] = 1LL << i;
    }
  }


  for(int i=0; i<=60; i++) {
    int id = -1;

    for(int j=0; j<N; j++) {
      if (b[j] < (1LL << ((60-i)+1)) && (1LL << (60-i)) & b[j]) {
        id = j;
        break;
      }
    }

    if (id == -1) continue;

    swap(b[i], b[id]);

    for(int j=0; j<N; j++) {
      if (j == i) continue;
      if((1LL << (60-i)) & b[j]) b[j] ^= b[i];
    }
  }

  for(int i=0; i<N; i++) {
    debug(b[i]);
  }

  ll ans = 0;

  for(int i=0; i<=60; i++) {
    if(!((1LL << (60-i)) & sum)) {
      ans ^= b[i];
      sum ^= b[i];
    }
  }

  cout << ans + sum << endl;

  return 0;
}
