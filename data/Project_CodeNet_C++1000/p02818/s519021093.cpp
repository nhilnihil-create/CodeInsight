#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

int main() {
  long long A, B, K;
  cin >> A >> B >> K;
  if(K <= A) {
    cout << A - K << " " << B << endl;
  } else if(K <= A + B) {
    cout << 0 << " " << A + B - K << endl;
  } else {
    cout << 0 << " " << 0 << endl;
  }
  return 0;
}