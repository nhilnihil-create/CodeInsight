#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
using namespace std;
typedef long long ll;

int main()
{
  ll N, K;
  cin >> N >> K;
  ll res;

  res = -N % K;
  if(res<0) res += K;
  res = min(res, N % K);

  cout << res << endl;
}