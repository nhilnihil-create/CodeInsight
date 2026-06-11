#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  int N;
  cin >> N;
  long long A[N];
  rep(i, N)
    cin >> A[i];
  // 入力終了

  long long money = 1000;
  long long num;

  rep(i, N-1){
    // 翌日の株の方が儲けられる
    if(A[i] < A[i+1]){
      // 所持金で限界まで株を買う
      num = money/A[i];
      money = money - num*A[i];

      // 所持株で限界まで金に換算
      money = money + num*A[i+1];
    }
  }

  // 解答
  cout << money << endl;
  
  
  return 0;
}
