#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;


int main() {
  int n; cin >> n;

  vector<int> a(n+1,0); 
  rep(i,n+1) {
    if(i == 0) continue;
    cin >> a[i];
  }

  vector<int> b(n+1,0);
  int m = 0;

  for(int i = n; i >= 1; i--){
    int tmp = i;
    int tmp2 = i;
    int tmp_b = 0;
    while(tmp < n+1) {
      tmp_b += b[tmp];
      tmp_b %= 2;
      tmp += tmp2;
    }

    tmp_b += a[i];
    tmp_b %= 2;

    b[i] = tmp_b;
    if(b[i] == 1) m++;
    
  }

  cout << m << endl;

  rep(i,n+1) {
    if(i == 0) continue;
    if(b[i] == 1) {
      cout << i << endl;
    }
  }
}

