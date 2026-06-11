#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vi d(n);
  rep(i,n) cin >> d[i];
  sort(d.begin(),d.end());
  cout << d[n/2] - d[n/2-1] << endl;
}
