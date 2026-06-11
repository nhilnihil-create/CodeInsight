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

int H, W, A, B;
void print_ans(int a, int b)
{
  vector<vector<int>> ans;
  rep(i, H)
  {
    int zero_number;
    if (i < a)
      zero_number = A;
    else
      zero_number = W - A;
    vector<int> v;
    rep(j, zero_number)
    {
      v.push_back(0);
    }
    rep(j, W - zero_number)
    {
      v.push_back(1);
    }
    ans.push_back(v);
  }

  for (int i = 0; i < W; i++)
  {
    int max_count;
    if (i < b)
      max_count = B;
    else
      max_count = H - B;

    int count = 0;
    rep(j, H)
    {
      if (ans[j][i] == 0)
        count++;
    }

    rep(j, H)
    {
      if (count == max_count)
        break;

      if (ans[j][i] == 1 && count < max_count)
      {
        for (int ni = i + 1; ni < W; ni++)
        {
          if (ans[j][ni] == 0)
          {
            swap(ans[j][i], ans[j][ni]);
            count++;
            break;
          }
        }
      }
      else if (ans[j][i] == 0 && count > max_count)
      {
        for (int ni = i + 1; ni < W; ni++)
        {
          if (ans[j][ni] == 1)
          {
            swap(ans[j][i], ans[j][ni]);
            count--;
            break;
          }
        }
      }
    }
  }

  rep(i, H)
  {
    rep(j, W)
    {
      cout << ans[i][j];
    }
    cout << endl;
  }
}

int main()
{
  cin >> H >> W >> A >> B;
  rep(a, H + 1)
  {
    int denominator = 2 * B - H;
    int numerator = (2 * A - W) * a - (A * H) + (B * W);
    if (numerator % denominator != 0)
      continue;
    int b = numerator / denominator;
    if (b < 0 || b > W)
      continue;
    print_ans(a, b);
    return 0;
  }

  cout << "No" << endl;
  return 0;
}