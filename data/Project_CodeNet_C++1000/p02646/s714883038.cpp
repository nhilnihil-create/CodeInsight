#include <bits/stdc++.h>
using namespace std;

int main() { 
  int A, V, B, W, T;
  cin >> A >> V >> B >> W >> T;
  
  long long int dist = max(A-B,0) + max(B-A,0);
  long long int speed = V-W;//1秒間でどれだけ距離を詰められるか？
  
  if( speed <= 0) cout << "NO" << endl;//おいつけない
  else if( speed * T >= dist ) cout << "YES" << endl;//時間内に追いつける
  else cout << "NO" << endl;//時間が足りない
}