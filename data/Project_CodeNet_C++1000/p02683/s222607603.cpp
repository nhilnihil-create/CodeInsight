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

int main()
{
  int N, M, X;
  cin >> N >> M >> X;
  vector<int> C(N);
  vector<vector<int>> input(N, vector<int>(M, 0));
  for (int i = 0; i < N; i++)
  {
    cin >> C[i];
    for (int j = 0; j < M; j++)
      cin >> input[i][j];
  }
  int maxim = 1 << 25;
  int ans = maxim;
  for (int bit = 0; bit < (1 << N); bit++)
  {
    vector<int> score(M, 0);
    int cost = 0;
    for (int i = 0; i < N; i++)
      if ((bit >> i) & 1)
      {
        cost += C[i];
        for (int j = 0; j < M; j++)
          score[j] += input[i][j];
      }
    bool ok = true;
    for (int i = 0; i < M; i++)
      if (score[i] < X)
        ok = false;
    if (ok && ans > cost)
    {
      ans = cost;
    }
  }
  if (ans == maxim)
    ans = -1;
  cout << ans << endl;

  return 0;
}
