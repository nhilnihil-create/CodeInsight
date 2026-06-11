#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  ll a, ans, c;
  double b;
  cin >> a >> b;
  c=b*100+0.1;
  ans=a*c/100;
  cout << ans << endl;

  return 0;
}