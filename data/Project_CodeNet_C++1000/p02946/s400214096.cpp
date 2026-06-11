#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{

  int n, k;
  cin >> n >> k;
  int x = k - n + 1;
  int cnt = 0;
  n = n * 2 - 1;
  while (cnt < n){
    cout << x << " ";
    cnt++;
    x++;
  }
  cout << endl;
  return 0;
}