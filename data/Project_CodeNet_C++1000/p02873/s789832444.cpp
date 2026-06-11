#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  string S;
  cin >> S;
  //入力終了
  
  int N = S.size();
  int constant_left_greater[N+1] = {0};
  int constant_right_less[N+1] = {0};
  int tmp = 0;

  //左に< が連続する回数を数える
  rep(i, N){
    if(S[i] == '<')
      tmp++;
    else
      tmp = 0;
    constant_left_greater[i+1] = tmp;
  }

  //右に> が連続する回数を数える
  tmp = 0;
  for(int i=N-1; i>=0; i--){
    if(S[i] == '>')
      tmp++;
    else
      tmp = 0;
    constant_right_less[i] = tmp;
  }


  //連続する< または> の数のうち大きい方を足していく
  long long ans = 0;
  rep(i, N+1){
    long long a = constant_left_greater[i];
    long long b = constant_right_less[i];
    ans += max(a, b);
  }

  //解答
  cout << ans << endl;
  
  return 0;
}
