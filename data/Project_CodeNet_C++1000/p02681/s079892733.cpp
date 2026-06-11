#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const long long INF = 1LL << 60;

string s,t;

int main()
{
  cin >> s >> t;
  bool check = false;
  rep(i,s.size())
  {
    if(s[i] != t[i]) check = true;
  }
  if(check) cout << "No" << endl;
  else cout << "Yes" << endl;
}