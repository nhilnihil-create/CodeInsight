#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using vi = vector<int>;

int main() {
  int n;
  cin >> n;
  vi p(n), q(n);
  rep(i,n) cin >> p[i];
  rep(i,n) cin >> q[i];
  
  vi a(n);
  rep(i,n) a[i] = i+1;
  
  int cnt = 0, A, B;
  do {
    if (p==a) A = cnt;
    if (q==a) B = cnt;
    cnt++;
  }while(next_permutation(a.begin(), a.end()));
  
  cout << abs(A-B) << endl;
}