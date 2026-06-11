#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  int N;
  cin >> N;
  long long sum = 0;
  vector<long long> A(N), D1(N), D2(N);
  rep(i, N)
  {
    cin >> A[i];
    sum += A[i];
    D1[i] = A[i];
    D2[i] = A[i];
  }

  REVERSE(D2);
  rep(i, N - 1)
  {
    D1[i + 1] += D1[i];
    D2[i + 1] += D2[i];
  }

  long long harf = sum / 2;
  long long ans = INT64_MAX;

  rep(i, N)
  {
    if (sum % 2 == 0 && D1[i] == harf)
    {
      ans = 0;
      break;
    }
    else if (D1[i] > harf)
    {
      for (int length = -1; length < 2; length++)
      {
        long long target = harf + length;
        ans = min(ans, abs(D1[i] - target) + abs(sum - D1[i] - target));
      }
      break;
    }
  }

  rep(i, N)
  {
    if (D2[i] > harf)
    {
      for (int length = -1; length < 2; length++)
      {
        long long target = harf + length;
        ans = min(ans, abs(D2[i] - target) + abs(sum - D2[i] - target));
      }
      break;
    }
  }

  cout << ans << endl;
  return 0;
}