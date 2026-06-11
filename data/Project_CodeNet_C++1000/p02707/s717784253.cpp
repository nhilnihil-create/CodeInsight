#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
int main() {
  int N; cin >> N;
  vvi A(N, vi(2,0));
  rep(i, N) A[i][0] = i;
  rep2(i, 1, N) {int s; cin >> s; A[s-1][1]++;}
  rep(i, N) cout << A[i][1] << endl;
}