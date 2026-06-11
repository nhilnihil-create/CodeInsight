#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll A, B, C, K;
  cin >> A >> B >> C >> K;
  ll A_num = min(A, K);
  if(A_num ==K){
      cout << A_num << endl;
      return 0;
  }
  ll B_num = min(B, K-A_num);
  if(A_num+B_num ==K){
    cout << A_num << endl;
    return 0;
  }
  ll C_num = K-A_num-B_num;
  cout << A_num-C_num << endl;
  return 0;
}