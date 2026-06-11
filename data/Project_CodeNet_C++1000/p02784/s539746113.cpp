#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, h; cin >> h >> n ;
  int total = 0;
  int num = 0;
  for(int i = 0; i < n; ++i)
  {
    cin >> num; total += num;
  }
  cout << (h > total ? "No" : "Yes");
  return 0;
}