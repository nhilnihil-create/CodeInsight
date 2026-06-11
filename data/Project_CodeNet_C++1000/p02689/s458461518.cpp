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

void solve(long long N, long long M, std::vector<long long> H, std::vector<long long> A, std::vector<long long> B)
{

  vector<vector<int>> adj(N);
  for (int i = 0; i < M; i++)
  {
    int u = A[i];
    int v = B[i];
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int ret = 0;
  for (int i = 0; i < N; i++)
  {
    int cnt = 0;
    for (auto v : adj[i])
      if (H[v] >= H[i])
        cnt++;
    if (cnt == 0)
      ret++;
  }
  cout << ret << endl;
}

int main()
{
  cout << setprecision(10);
  long long N;
  scanf("%lld", &N);
  long long M;
  scanf("%lld", &M);
  std::vector<long long> H(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &H[i]);
  }
  std::vector<long long> A(M);
  std::vector<long long> B(M);
  for (int i = 0; i < M; i++)
  {
    scanf("%lld", &A[i]);
    scanf("%lld", &B[i]);
  }
  solve(N, M, std::move(H), std::move(A), std::move(B));
  return 0;
}
