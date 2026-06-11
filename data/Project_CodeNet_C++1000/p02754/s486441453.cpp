#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N, A, B;
  cin >> N >> A >> B;
  int64_t sho, amari;
  sho = N / (A + B);
  amari = N % (A + B);
  int64_t amari_dash;
  if (amari > A) amari_dash = A;
  else amari_dash = amari;
  cout << sho * A + amari_dash;
}