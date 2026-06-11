#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  ll A, B, K;
  cin >> A >> B >> K;

  ll eat = min(A + B, K);  //高橋君が食べたクッキーの枚数
  if (eat <= A){
    cout << A - eat << " " << B << endl;
  }else{
    cout << 0 << " " <<  A + B - eat << endl;
  }
}
