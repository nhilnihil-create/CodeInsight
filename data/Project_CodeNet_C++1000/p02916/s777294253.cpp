#include <bits/stdc++.h>
using namespace std;

int main() {
  //宣言と入力.合計
  int N,x=0;
  cin >> N;
  vector<int>a(N);
  vector<int>b(N);
  vector<int>c(N);
  for(int i=0; i<N; i++)cin >> a[i];
  for(int i=0; i<N; i++){
    cin >> b[i];
    x += b[i];
  }
  for(int i=0; i<N; i++)cin >> c[i];
  //特例計算
  for(int i=0; i<N-1; i++){
    if(a[i+1]-a[i] == 1){
      x += c[a[i]-1];
    }
  }
  cout << x << endl;
}
