#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  ll n, a, b;
  cin >> n >> a >> b;
  ll c=n/(a+b)*a, d=n%(a+b);
  if(d<a)cout << c+d << endl;
  else cout << c+a << endl;

  return 0;
}