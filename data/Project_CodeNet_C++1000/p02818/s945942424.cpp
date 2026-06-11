#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll A, B, K;
  cin >> A >> B >> K;

  if (K >= A + B){
    cout << 0 << " " << 0 << endl;
  }else if (K >= A){
    cout << 0 << " " << B-(K-A) << endl;
  }else{
    cout << A-K << " " << B << endl;
  }

  return 0;
}