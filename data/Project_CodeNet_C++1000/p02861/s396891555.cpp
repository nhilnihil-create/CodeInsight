#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;

  //入力
  cin >> n;
  vector<int> x(n), y(n), a(n);
  double k = 1;
  rep(i, n) {
    cin >> x.at(i) >> y.at(i);
    a.at(i) = i;
    k *= i+1;
    //cout << x.at(i) << y.at(i) << a.at(i) << k << endl;
  }

  //中身
  double sum = 0; int i, j;
  do{
    rep(l, n-1){
      i = a.at(l+1);
      j = a.at(l);
      sum += sqrt(pow(x.at(i)-x.at(j), 2) + pow(y.at(i)-y.at(j), 2));
    }
  }while(next_permutation(a.begin(), a.end()));

  double avr = sum / k;
  
  
  cout << fixed << setprecision(10) << avr << endl;
  return 0;
}
