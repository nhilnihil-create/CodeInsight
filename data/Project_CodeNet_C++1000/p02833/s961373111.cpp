#include <iostream>

using namespace std;

int main(void){
  long long N;
  cin >> N;
  // 入力終了
  
  // f(N) = N(N-2)(N-4)(N-6) ...  
  // となり，偶数のときのみ0が末尾につく

  // 奇数のときは，
  // f(N) = N(N-2)(N-4)(N-6) ... 3 1
  // なので10を素因数に持たない
  if(N%2){
    cout << 0 << endl;
    return 0;
  }

  // Nの桁数を見る
  long long tmp = N;
  long long dig = 0;
  while(tmp != 0){
    dig++;
    tmp /= 10;
  }

  // 素因数5より素因数2の方が明らかに多く現れるので
  // 素因数5が何回現れるかだけに着目すれば十分
  long long ans = 0;
  tmp = 5;
  while(1){
    // 5^nで何回割れるか
    // ただし，奇数のときは除く
    ans += (N/tmp)/2;
    tmp *= 5;

    if(tmp > N)
      break;
  }
  
  // 解答
  cout << ans << endl;
  
  return 0;
}
