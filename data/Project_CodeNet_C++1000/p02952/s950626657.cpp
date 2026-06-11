#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, d=1;
  cin >> n;

  int ans;
  if(n<10)ans=n;
  else if(n<100)ans=9;
  else if(n<1000)ans=9+(n-99);
  else if(n<10000)ans=909;
  else if(n<100000)ans=909+(n-9999);
  else ans=90909;

  cout << ans << endl;

  return 0;
}