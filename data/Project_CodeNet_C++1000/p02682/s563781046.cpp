#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const long long INF = 1LL << 60;

ll a,b,c,k;

int main()
{
  cin >> a >> b >> c >> k;
  if(k <= a) cout << k << endl;
  else if(k <= (a+b)) cout << a << endl;
  else cout << a-(k-b-a) << endl;
}