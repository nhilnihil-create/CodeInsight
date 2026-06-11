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

void solve(long long X, long long N, std::vector<long long> p)
{

  set<int> vals;
  for (auto pp : p)
    vals.insert(pp);

  for (int i = 0; i < 100; i++)
  {
    int val = X - i;
    if (vals.find(val) == vals.end())
    {
      cout << val << endl;
      return;
    }
    val = X + i;

    if (vals.find(val) == vals.end())
    {
      cout << val << endl;
      return;
    }
  }
}

int main()
{
  cout << setprecision(10);
  long long X;
  scanf("%lld", &X);
  long long N;
  scanf("%lld", &N);
  std::vector<long long> p(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &p[i]);
  }
  solve(X, N, std::move(p));
  return 0;
}
