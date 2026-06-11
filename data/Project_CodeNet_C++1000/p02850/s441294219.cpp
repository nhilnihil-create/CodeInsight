#include <bits/stdc++.h>

typedef uint64_t u64;
typedef int64_t i64;
typedef uint32_t u32;
typedef int32_t i32;

#define MAX_NUM (1000000000 + 7)

using namespace std;

template <typename T>
static inline void ArrayInput(vector<T>& A) {
  for (auto itr = A.begin(); itr < A.end(); ++itr) cin >> *itr;
}

template <typename T>
static inline void ArrayPut(const vector<T>& A) {
  for (auto itr = A.begin(); itr < A.end(); ++itr) cout << *itr << " ";
  cout << endl;
}

template <typename T>
static inline T ArraySum(vector<T>& A) {
  T res = 0;
  for (auto itr = A.begin(); itr < A.end(); ++itr) res += *itr;
  return res;
}

bool Sec_compare(pair<uint64_t, uint64_t> a, pair<uint64_t, uint64_t> b) {
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return a.first < b.first;
  }
}

u64 dec_dig(u64 num) {
  u64 res = 0;
  while (num > 0) {
    num /= 10;
    ++res;
  }
  return res;
}

i64 modinv(i64 a, i64 m) {
  i64 b = m, u = 1, v = 0;
  while (b) {
    i64 t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

u64 gcd(u64 a, u64 b) {
  if (a < b) {
    a ^= b;
    b ^= a;
    a ^= b;
  }

  return b ? gcd(b, a % b) : a;
}

u64 My_Combination(u64 n, u64 k, i64 m) {
  if (n < k) return 0;
  if (k == 0 || n == k) return 1;
  u64 res = 1;
  for (u64 i = 1; i <= k; ++i)
    res = (((res * (n + 1 - i)) % m) * modinv(i, m)) % m;
  return res;
}

int main() {
  cout << setprecision(18);
  u32 N;
  cin >> N;
  vector<vector<u32>> Tree(N);
  map<pair<u32, u32>, u32> res;
  vector<pair<u32, u32>> route(N - 1);
  for (u32 i = 0; i < N - 1; ++i) {
    u32 a, b;
    cin >> a >> b;
    Tree[a - 1].push_back(b - 1);
    Tree[b - 1].push_back(a - 1);
    res[make_pair(a - 1, b - 1)] = 0;
    route[i] = make_pair(a - 1, b - 1);
  }
  u32 max_node = 0;
  u32 max_size = 0;
  for (u32 i = 0; i < N; ++i) {
    if (max_size < Tree[i].size()) {
      max_size = Tree[i].size();
      max_node = i;
    }
  }
  vector<bool> achieve(N, false);
  queue<u32> Next;
  Next.push(max_node);
  achieve[max_node] = true;
  while (!Next.empty()) {
    u32 next_node = Next.front();
    Next.pop();
    set<u32> Col;
    u32 c = 1;
    for (auto itr = Tree[next_node].begin(); itr != Tree[next_node].end();
         ++itr) {
      u32 a = *itr, b = next_node;
      if (a > b) swap(a, b);
      if (res[make_pair(a, b)] != 0) Col.insert(res[make_pair(a, b)]);
    }
    for (auto itr = Tree[next_node].begin(); itr != Tree[next_node].end();
         ++itr) {
      if (achieve[*itr]) continue;
      u32 a = *itr, b = next_node;
      if (a > b) swap(a, b);
      if (res[make_pair(a, b)] == 0) {
        while (Col.find(c) != Col.end()) {
          ++c;
        }
        res[make_pair(a, b)] = c;
        Col.insert(c);
      }
      achieve[*itr] = true;
      Next.push(*itr);
    }
  }
  cout << max_size << endl;
  for (auto itr = route.begin(); itr != route.end(); ++itr) {
    cout << res[*itr] << endl;
  }

  return 0;
}
