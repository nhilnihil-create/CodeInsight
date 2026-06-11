#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int A, B, C, K;
  cin >> A >> B >> C >> K;

  int max = 0;
  int remain = K;

  if (K >= A){
    max += A;
    remain -= A;
  }
  else
  {
    max += K;
    remain = 0;
  }

  if (K >= A + B){
    remain -= B;
  }
  else
  {
    remain = 0;
  }
  

  if (K >= A + B + C){
    max -= C;
  }
  else
  {
    if (remain > 0)  max -= remain;
  }
  
  cout << max << endl;
}