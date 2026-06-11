//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main(){
  int n;
  cin >> n;
  vector<long long> A(n), A_copy(n), data(n);
  rep1(i, n){
    cin >> A[i];
    A_copy[i] = A[i];
  }
  
  sort(A.begin(), A.end());
  vector<long long> kaisu_lan_A; // 答えを格納
  for (int l = 0; l < n;) {
    int r = 0;
    for (; l+r < n && A[l] == A[l+r]; r++) {
      data[A[l]-1] += 1;
    }
    kaisu_lan_A.push_back(r);
    l += r;
  }

  long long sum = 0;
  rep1(i, kaisu_lan_A.size()){
  long long tem = kaisu_lan_A[i];
    sum += tem*(tem-1)/2;
  }

  rep1(i, n){
    long long tem = data[A_copy[i]-1];
    cout << sum - tem*(tem-1)/2 + (tem-1)*(tem-2)/2 << endl;
  }



}
