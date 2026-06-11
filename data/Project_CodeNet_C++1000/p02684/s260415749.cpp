#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  long long K;
  cin >> N >> K;
  vector<long long> A(N), B(N,-1);
  for (long long i=0; i<N; i++) {
    cin >> A[i];
    A[i]--;
  }
  B[0]=0;
  long long pos=0, shuuki=0;
  long long machi;
  for (long long i=1; i<=K; i++) {
    pos=A[pos];
    //cout << pos << endl;
    if (B[pos]==-1) {
      B[pos]=i;
      continue;
    }
    else {
      shuuki = i-B[pos];
      //cout << B[pos] << endl;
      break;
    }
  }
  if (shuuki!=0) {
    K-=B[pos];
    long long mm = K-(K/shuuki)*shuuki;
    long long k=B[pos]+mm;
    for (long long i=0; i<N; i++) {
      if (B[i]==k) {
        machi=i+1;
        break;
      }
    }
  }
  else {
    machi=pos+1;
  }
  //cout << shuuki << endl;
  cout << machi << endl;
}
