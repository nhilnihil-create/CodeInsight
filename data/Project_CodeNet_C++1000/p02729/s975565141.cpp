#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const long long INF = 1LL << 60;

int n,m;

int main()
{
  cin >> n >> m;
  cout << n*(n-1)/2+m*(m-1)/2 << endl;
}