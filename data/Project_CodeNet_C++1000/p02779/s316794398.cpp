#include <bits/stdc++.h>
using namespace std;
#define rep(i,A) for(int i = 0;i < A;i++)

int main() {
  int A;
  cin >> A;
  int B[A];
  int C = 1;
  int count = 0;
  rep(i,A){
    cin >> B[i];
  }
  sort(B,B + A);
  rep(i,A){
    if(B[i] == B[C]){
      count++;
    }
    C++;
  }
  if(count > 0){
    cout << "NO" << endl;
  }
else{
  cout << "YES" << endl;
}
}
