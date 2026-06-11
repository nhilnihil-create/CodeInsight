#include<bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

int main(){
  //点i,j間の最短距離はmin(|j - i|, |X-i| + |Y-j| + 1(この1はY - X), |X - j| + |Y - i| + 1)
  int N , X , Y;
  cin >> N >> X >> Y;
  vector<int>A(N,0); //カウントしていく k番目に入ってる個数
  //まずは最短距離を調べる
  int mind = 2000; // N < 2 * 10^3より，十分大きい値
  for(int i = 1; i <= N -1; i++){
    for(int j = i + 1 ; j <= N; j++){
      mind = min(abs(j - i), min(abs(X - i)+ 1 +abs(Y - j), abs(Y - i) + 1 + abs(X - j) ) ) ;
      A[mind]++;
    }
  }
  for(int k = 1; k < N; k++){
    cout << A[k] << endl;
  }
}
