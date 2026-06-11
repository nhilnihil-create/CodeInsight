#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N, L;
  cin >> N >> L;

  int abs_min = 999999;
  int abs_i = 0;

  for (int i = 1; i <= N; i++){
    if (abs(L + i - 1) < abs_min){
      abs_min = abs(L + i - 1);
      abs_i = i;
    }
  }

  int sum = 0;
  for (int i = 1; i <= N; i++){
    if (i != abs_i) sum += L + i - 1;
  }

  cout << sum << endl;
}