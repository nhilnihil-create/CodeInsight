#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PII;

// chmax, chmin
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}

template <typename T>
function<T(T, T)> op_max = [](T a, T b) -> T { return max(a, b); };
template <typename T>
function<T(T, T)> op_min = [](T a, T b) -> T { return min(a, b); };

template <typename T>
function<T(T, T)> op_sum = [](T a, T b) -> T { return a + b; };

using namespace std;
//********************  dumps ************************//

template <typename T>
void dump(const T &data, vector<int> &iter)
{
  cout << data << " ";
}
template <typename T>
void dump(const vector<T> &data, vector<int> &iter)
{
  for (auto elem : data)
    dump(elem, iter);
  cout << endl;
}

template <typename T>
void dump(const vector<vector<T>> &data, vector<int> &iter)
{
  for (auto elem : iter)
  {
    cout << "[" << elem << "]";
  }
  cout << endl;
  for (int i = 0; i < data.size(); i++)
  {
    iter.push_back(i);
    dump(data[i], iter);
    iter.pop_back();
  }
  cout << endl;
}

template <typename T>
void dump(const vector<T> &data, int dummy)
{
  for (int i = 0; i < data.size(); i++)
  {
    cout << "[" << i << "] " << data[i] << endl;
  }
}
template <typename T>
void dump(const T &data)
{ // T : data, U = base type val.
  vector<int> iter;
  dump(data, iter);
}
///////////////////////////////////////////////

void solve(long long N, long long M, long long Q, std::vector<long long> a, std::vector<long long> b, std::vector<long long> c, std::vector<long long> d)
{
  LL ans = 0;
  function<void(vector<int>)> dfs = [&](vector<int> cur) {
    int n = cur.size();
    if (n == 0)
    {
      for (int i = 1; i <= M; i++)
      {
        auto nxt = cur;
        nxt.push_back(i);
        dfs(nxt);
      }
      return;
    }
    if (n == N)
    {
      LL score = 0;
      for (int i = 0; i < Q; i++)
      {
        int A = a[i] - 1;
        int B = b[i] - 1;
        int C = c[i];
        int D = d[i];
        if (cur[B] - cur[A] == C)
          score += D;
      }
      chmax(ans, score);
      return;
    }
    for (int i = cur.back(); i <= M; i++)
    {
      auto nxt = cur;
      nxt.push_back(i);
      dfs(nxt);
    }
  };
  vector<int> data;
  dfs(data);
  cout << ans << endl;
}

int main()
{
  cout << setprecision(10);
  long long N;
  scanf("%lld", &N);
  long long M;
  scanf("%lld", &M);
  long long Q;
  scanf("%lld", &Q);
  std::vector<long long> a(Q);
  std::vector<long long> b(Q);
  std::vector<long long> c(Q);
  std::vector<long long> d(Q);
  for (int i = 0; i < Q; i++)
  {
    scanf("%lld", &a[i]);
    scanf("%lld", &b[i]);
    scanf("%lld", &c[i]);
    scanf("%lld", &d[i]);
  }
  solve(N, M, Q, std::move(a), std::move(b), std::move(c), std::move(d));
  return 0;
}
