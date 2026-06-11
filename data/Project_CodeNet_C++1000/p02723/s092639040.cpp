#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const long long INF = 1LL << 60;

string s;

int main()
{
  cin >> s;
  if(s[2] == s[3] && s[4] == s[5]) cout << "Yes" << endl;
  else cout << "No" << endl;
}