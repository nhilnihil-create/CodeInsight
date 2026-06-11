#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979323846;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i=0; i<N; i++) cin >> a[i];
  vector<int> b(N, 0);
  for (int i=N-1; i>=0; i--) {
    int sum = 0;
    for (int j=i; j<N; j+=i+1) sum += b[j];
    if (sum%2==0&&a[i]%2!=0) b[i] = 1;
    else if (sum%2!=0&&a[i]%2==0) b[i] = 1;
    else b[i] = 0;
  }
  int M = 0;
  for (int i=0; i<N; i++) {
    if (b[i]==1) M++;
  }
  cout << M << endl;
  for (int i=0; i<N; i++) {
    if (b[i]==1) cout << i+1 << " ";
  }
  cout << endl;
  return 0;
}