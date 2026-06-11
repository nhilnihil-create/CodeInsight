#include <algorithm>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> A(N);
  long long y = 0;
  for(int i = 0; i < N; ++i)
    cin >> A[i], y ^= A[i];
  int idx = 0;
  for(auto &a : A) a &= ~y;
  for(int i = 60; i >= 0; --i){
    int k = -1;
    for(int j = idx; j < N; ++j){
      if((A[j]>>i)&1){
        k = j;
        break;
      }
    }
    
    if(k >= 0){
      swap(A[idx],A[k]);

      for(int j = 0; j < N; ++j){
        if(j == idx) continue;
        if((A[j]>>i)&1)
          A[j] ^= A[idx];
      }
      ++idx;
    }
  }
  // for(auto a : A)
  //   cerr << (bitset<60>)a << endl;
  long long x = 0;
  for(int i = 0; i < N; ++i){
    x ^= A[i];
    // if((x^A[i]) > x) x ^= A[i];
  }
  y ^= x;
  cerr << x << " " << y << endl;
  cout << x+y << endl;
}
