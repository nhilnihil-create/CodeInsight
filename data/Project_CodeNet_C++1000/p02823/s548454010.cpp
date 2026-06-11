#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
ll INF = 1000000000;
int main()
{
  ios::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
  ll n,a,b;
  cin>>n>>a>>b;
  ll ans = 0;
//  int dist = min(n-max(a,b), min(a,b)-1);
  if(abs(a - b) %2 == 0)
    ans = abs(a-b)/2;
  else
    ans = min((a+b-1)/2, ((2*n)-a-b+1)/2);
  cout << ans << endl;
}