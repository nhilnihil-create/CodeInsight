#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const long long INF = 1LL << 60;

int n;
string s;

int main()
{
  cin >> n >> s;
  rep(i,s.size())
  {
    int x = s[i] - 'A';
    s[i] = 'A'+ (x+n)%26;
  }
  cout << s << endl;
}