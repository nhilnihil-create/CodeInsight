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

const string YES = "Yes";
const string NO = "No";

void solve(long long X, long long Y)
{

  for (int i = 0; i <= 100; i++)
    for (int j = 0; j <= 100; j++)
    {
      if (i + j == X && 2 * i + 4 * j == Y)
      {
        cout << YES << endl;
        return;
      }
    }
  cout << NO << endl;
}

int main()
{
  cout << setprecision(10);
  long long X;
  scanf("%lld", &X);
  long long Y;
  scanf("%lld", &Y);
  solve(X, Y);
  return 0;
}
