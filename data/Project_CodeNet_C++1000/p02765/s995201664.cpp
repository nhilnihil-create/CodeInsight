#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const long long INF = 1LL << 60;

int n,r;

int main()
{
  cin >> n >> r;
  if(n >= 10) cout << r << endl;
  else cout << r+100*(10-n) << endl;
}