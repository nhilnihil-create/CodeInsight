#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define Rep(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define ll long long int
#define INF 1e9
#define LINF 1e18
#define MOD 1000000007
#define PI 3.14159265359
#define EPS 1e-10
#define All(a) (a).begin(), (a).end()

using namespace std;
using P = pair<ll, ll>;
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

/**
 * Usage:
 * 
 * G[from].push_back(Edge(to, weight));
 * using Graph = vector<vector<Edge>>;
 * 
 */ 
struct Edge {
  int to;     
  ll weight; 
  Edge(int t, ll w) : to(t), weight(w) { }
};

/**
 * Usage:
 * 
 * chmin(old, new);
 * chmax(old, new);
 * 
 */ 
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T>
void printv(vector<T>& v) {
  if (v.size() == 0) {
    cout << "\n";
    return;
  }

  Rep(i, v.size()) {
    cout << v[i] << ((i + 1 < v.size()) ? ' ' : '\n');
  }
}




int N, K;
ll a[210000];

void update() {
  ll tmp[210000];

  Rep(t, N) {
    tmp[t] = 0;
  }

  Rep(i, N) {
    ll y = a[i];
    int left = i - y;
    int right = i + y + 1;

    //cout << i << "\n";
    //cout << left << " " << right << "\n";

    if (left >= 0) {
      tmp[left] += 1;
    } else {
      tmp[0] += 1;
    }
    if (right < N) {
      tmp[right] -= 1;
    }
    //cout << i << "\n";
  }

  ll re = 0;

  Rep(i, N) {
    re += tmp[i];
    a[i] = re;
  }
}


int main () {
  cin >> N >> K;

  Rep(i, N) cin >> a[i];

  if (K < 100) {
    Rep(q, K) update();

    Rep(i, N) {
      cout << a[i] << ((i + 1 < N) ? ' ' : '\n');
    }
  } else {
    Rep(i, N) {
      cout << N << ((i + 1 < N) ? ' ' : '\n');
    }
  }
}