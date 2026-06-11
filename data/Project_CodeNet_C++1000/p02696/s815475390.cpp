#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n)for(int i=0; i<n; i++)

int main(){
  int A;
  long long B, N;
  cin >> A >> B >> N;
  //入力終わり

  //xに対してx+Bは同じ値を取る
  //法がBみたいなかんじ

  //最大なのはB-1だが，それがNを超えていてはいけない
  long long m = min(B-1, N);

  cout << A*m/B - A*(m/B) << endl;
  
  return 0;
}
