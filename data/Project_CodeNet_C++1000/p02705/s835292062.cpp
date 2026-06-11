#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T &a, T b) {if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T &a, T b) {if (a > b) {a = b;return 1;}return 0;}

int main(){
  double r;
  cin >> r;
  const double PI=3.14159265358979323846;
  cout << std::fixed << std::setprecision(15) << 2 * r * PI << endl;
}
