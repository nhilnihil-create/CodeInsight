#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const long long INF = 1LL << 60;

int h,a;

int main()
{
  cin >> h >> a;
  cout << (h+a-1)/a << endl;
}