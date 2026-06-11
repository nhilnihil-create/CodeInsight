#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

#define FOR(i, N) for (int i = 0; i < (int)N; i++)
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define MOD 1000000007
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

using Pi = pair<int, int>;
using ll = long long;
const int INF = 1 << 28;

string to_string(string s) { return s; }

template <class T>
string to_string(vector<T> v) {
  string ret = "{";
  for (int i = 0; i < v.size() - 1; ++i) {
    ret += to_string(v[i]) + ",";
  }
  if (v.size() > 0) {
    ret += to_string(v.back());
  }
  ret += "}";
  return ret;
}

void debug() { cerr << endl; }

template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

void print() { cout << endl; }

template <class Head, class... Tail>
void print(Head head, Tail... tail) {
  cout << to_string(head);
  print(tail...);
}

void get() {}

template <class Head, class... Tail>
void get(Head& head, Tail&... tail) {
  cin >> head;
  get(tail...);
}

template <class T>
void getv(vector<T>& vec) {
  for (int i = 0; i < vec.size(); ++i) cin >> vec[i];
}

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

int main() {
  cin.tie(0);
  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  FOR(i, N) cin >> A[i];
  FOR(i, N) cin >> B[i];
  priority_queue<Pll> can;
  FOR(i, N) {
    if (B[i] > A[i]) can.push(Pll(B[i], i));
  }
  ll ans = 0;
  while (!can.empty()) {
    Pll p = can.top();
    ll i = p.second;
    can.pop();
    ll bunbo = (B[i == 0 ? N - 1 : i - 1] + B[i == N - 1 ? 0 : i + 1]);
    ll num = p.first - A[i];
    ans += num / bunbo;
    num %= bunbo;
    if (B[i] == A[i] + num) {
      print(-1);
      return 0;
    }
    B[i] = A[i] + num;
    if (num != 0) can.push(Pll(B[i], i));
  }
  print(ans);
  return 0;
}
