#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main(){
  int A, B, M;
  cin >> A >> B >> M;
  vector<long long> a(A), b(B), x(M), y(M), c(M);
  rep(i,A) cin >> a.at(i);
  rep(i,B) cin >> b.at(i);
  rep(i,M) cin >> x.at(i) >> y.at(i) >> c.at(i);
  long long  mini = 200000;
  rep(i,M){
    if((a.at(x.at(i)-1)+b.at(y.at(i)-1) - c.at(i)) <= mini ){
      mini = (a.at(x.at(i)-1)+b.at(y.at(i)-1) - c.at(i));
    }
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  if(mini > a.at(0)+b.at(0) ) mini = a.at(0) + b.at(0);
  cout << mini << endl;
}