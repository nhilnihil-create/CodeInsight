#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <functional>
#include <map>
#include <set>
#define Rep(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define ll long long int
#define INF 100000000
#define INFLL 100000000000
#define MOD 1000000007
#define PI 3.14159265359
#define All(a) (a).begin(), (a).end()

using namespace std;
using P = pair<ll, ll>;
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Edge {
  int to;     
  ll weight; 
  Edge(int t, ll w) : to(t), weight(w) { }
};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int M;
ll length;
ll sum;

int main () {
  cin >> M;

  rep(i, M) {
    ll d, c;
    cin >> d >> c;

    length += c;
    sum += (d * c);
  }

  cout << (length-1) + (sum-1) / 9 << "\n";
}