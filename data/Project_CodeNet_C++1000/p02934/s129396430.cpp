#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair <int, int>;
const double PI = acos(-1);
const ll MOD = 1000000007;

int main() {
  int N;
  cin >> N;
  double sum=0;
  rep(i,N){
    int A;
    cin >> A;
    sum += 1.0/A;
  }

  cout << fixed << setprecision(10) << 1.0/sum << endl;


}
