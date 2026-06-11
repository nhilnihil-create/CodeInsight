#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,k,x,y;
string s,t;

int main() {
  cin >> x >> y;
  int ans=0;
  if(x==1 && y==1)
  ans+=400000;
  ans+=max(4-x,0)*100000+max(4-y,0)*100000;
  cout << ans << endl;
}