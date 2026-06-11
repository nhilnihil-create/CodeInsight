#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const long long INF = 1LL << 60;

int n;

int main()
{
  cin >> n;
  bool check = false;
  if(n/100 == 7 || (n/10)%10 == 7 || n%10 == 7) cout << "Yes" << endl;
  else cout << "No" << endl;
}