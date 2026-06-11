#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;
const int INF = 1001001001;


int main() {
  int n;
  cin >> n;
  int cnt = 0;
  rep(i,n){
    int a, b;
    cin >> a >> b;
    if(a==b){
      ++cnt;
      if(cnt == 3){
        cout <<"Yes"<< endl;
        return 0;
      }
    }
    else cnt=0;
  }
  cout << "No" << endl;
  return 0;
}