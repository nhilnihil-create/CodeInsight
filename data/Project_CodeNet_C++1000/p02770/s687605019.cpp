#include <bits/stdc++.h>
using namespace std;
int main(){
  long long k,q;
  cin >> k >> q;
  vector<long long> d(k);
  for (int i = 0; i < k; i++){
    cin >> d[i];
  }
  int n,x,m;
  //クエリ処理
  for (int i = 0; i < q; i++){
    cin >> n >> x >> m;
    //s: d%mの累積和
    vector<long long> s(k + 1);
    s[0] = 0;
    for (int i = 0; i < k; i++){
      s[i + 1] = s[i] + d[i] % m;
    }
    vector<bool> D(k);
    for (int i = 0; i < k; i++){
      if (d[i] % m == 0){
        D[i] = true;
      } else {
        D[i] = false;
      }
    }
    //M: 1-Dの累積和
    vector<int> M(k + 1);
    M[0] = 0;
    for (int i = 0; i < k; i++){
      if (D[i]){
        M[i + 1] = M[i];
      } else {
        M[i + 1] = M[i] + 1;
      }
    }
    long long A = (n - 1) / k * M[k] + M[(n - 1) % k];
    long long C = (x % m + (n - 1) / k * s[k] + s[(n - 1) % k]) / m;
    cout << A - C << endl;
  }
}