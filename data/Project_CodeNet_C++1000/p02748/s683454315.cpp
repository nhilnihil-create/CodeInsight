#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
void ins() {}
template<class T,class... Rest>void ins(T& v,Rest&... rest){cin>>v;ins(rest...);}
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
int main() {
  int A, B, M;
  ins(A, B, M);

  vi a(A), b(B);
  int min_a = 1e5, min_b = 1e5;
  rep(i, A) {
    cin >> a[i];
    chmin(min_a, a[i]);
  }
  rep(i, B) {
    cin >> b[i];
    chmin(min_b, b[i]);
  }

  int ans = min_a + min_b;
  rep(i, M) {
    int x, y, c;
    ins(x, y, c);

    chmin(ans, a[x-1] + b[y-1] - c);
  }
  cout << ans << endl;

  return 0;
}
