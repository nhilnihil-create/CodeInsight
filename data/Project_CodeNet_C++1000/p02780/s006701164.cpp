#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  double cnt; //解(期待値の最大値)
  double cndty; //期待値の最大値の候補を代入する
  cin >> n >> k;
  
  //C++では、動的配列の代わりにベクトルを使用すると超便利・・・らしい
  vector<double> p(n);
  
  for (int i = 0; i < n; i++){
    double p_in;
    cin >> p_in;
    p[i] = (p_in+1.0) / 2.0; //期待値はサイコロの最大の値さえわかれば、求められる
    //p.at(i) = (p+1.0) / 2.0;
  }
  
  vector<double> s(n+1);//累積和を求めるための配列（ベクトルだけども
  s[0] = 0;
  
  for( int i = 1 ; i < n+1 ; i++){
    s[i] = p[i-1] + s[i-1];
  }
  
  for( int i = 0;  n - k - i >= 0 ; i++){
    cndty = s[k+i] - s[i];
    
    if(cndty > cnt){
      cnt = cndty;
    }
  }
  
  cout << fixed << setprecision(12) << cnt << endl;
  
}