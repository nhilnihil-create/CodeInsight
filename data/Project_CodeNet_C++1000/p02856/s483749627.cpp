#include<iostream>
using namespace std;

int main(){
  long long D = 0, S = -1, S_cnt = 0;

  int M;
  cin >> M;
  for(int i = 0; i < M; i++){
    long long d, c;
    cin >> d >> c;
    D += c;
    S += d * c;
    S_cnt += S / 9;
    S %= 9;
  }

  cout << D - 1 + S_cnt << endl;
}
