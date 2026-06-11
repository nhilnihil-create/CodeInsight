#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int gcd(int p, int q){
  if(p%q==0)return q;
  return gcd(q, p%q);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;
  ll c=(ll)a*(ll)b;

  cout << c/gcd(a, b) << endl;

  return 0;
}