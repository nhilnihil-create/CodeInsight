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

  int n;
  cin >> n;
  int sum = 0;
  vi x(n);
  rep(i, n) {
      cin >> x[i];
      sum += x[i];
  }
  int a = sum / n, ans0=0, b=a+1, ans1=0;
  rep(i, n)ans0 += (x[i] - a) * (x[i] - a);
  rep(i, n)ans1 += (x[i] - b) * (x[i] - b);

  cout << min(ans0, ans1) << endl;

  return 0;
}