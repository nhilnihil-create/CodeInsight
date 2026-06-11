#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const long long INF = 1LL << 60;

int s,w;

int main()
{
  cin >> s >> w;
  if(w >= s) cout << "unsafe" << endl;
  else cout << "safe" << endl;
}