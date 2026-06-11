#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define ll long long
#define rep(i,n) for (int i = 1; i < (n); i++)

int main() {
  int N;
  cin >> N;
  int flag=0;
  rep(i,10) rep(j,10) if(i*j==N) flag=1;
  if(flag==1) cout << "Yes" << endl;
  else cout << "No" << endl;
}
