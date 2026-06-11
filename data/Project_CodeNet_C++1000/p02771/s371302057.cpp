#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const long long INF = 1LL << 60;

int a,b,c;

int main()
{
  cin >> a >> b >> c;
  int res = 0;
  if(a != b) res++;
  if(b != c) res++;
  if(c != a) res++;
  if(res == 2) cout << "Yes" << endl;
  else cout << "No" << endl;
}