#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
int main() {
  int k,x;
  cin >> k >> x;
  for(int i= -k; i<k-1; i++){
    cout << x + 1 +i << " ";
  }
}