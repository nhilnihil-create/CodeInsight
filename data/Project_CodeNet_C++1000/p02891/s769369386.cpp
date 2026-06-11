#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  long long K;
  cin >> K;
  string T = S + S;
  string T_ = S + S + S;
  long long N = S.size();
  long long count = 0;
  for (int i = 1; i < N; i++){
    if (S[i] == S[i - 1]){
      count++;
      i++;
    }
  }
  long long count_ = 0;
  for (int i = 1; i < 2 * N; i++){
    if (T[i] == T[i - 1]){
      count_++;
      i++;
    }
  }
  count_ -= count;
  long long count__ = 0;
  for (int i = 1; i < 3 * N; i++){
    if (T_[i] == T_[i - 1]){
      count__++;
      i++;
    }
  }
  count__ -= count + count_;
  
  if (count == count_) cout << count * K << endl;
  else {
    if (count_ == count__){
      cout << count + count_ * (K - 1) << endl;
    }
    else {
      if (K % 2 == 0) cout << (K / 2) * (count + count_) << endl;
      else cout << count + (count + count_) * ((K - 1) / 2) << endl;
    }
  }
}