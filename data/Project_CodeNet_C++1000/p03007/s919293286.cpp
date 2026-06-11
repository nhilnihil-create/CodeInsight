#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A;
  int abs_sum = 0;
  vector<int> pA;
  vector<int> mA;
  rep(i, N) {
    int A;
    cin >> A;
    abs_sum += abs(A);
    if (0 <= A)
      pA.emplace_back(A);
    else
      mA.emplace_back(A);
  }
  sort(pA.begin(), pA.end());
  sort(mA.begin(), mA.end(), greater<int>());

  int plus = pA.size();
  int minus = mA.size();
  int pi = 0;
  int mi = 0;
  if (plus == 0) {
    if (minus == 2) {
      cout << mA[1] - mA[0] << endl;
      cout << mA[1] << " " << mA[0] << endl;
      return 0;
    }
    abs_sum += (2 * mA[0]);
    cout << abs_sum << endl;
    cout << mA[0] << " " << mA[1] << endl;
    pA.emplace_back(mA[0] - mA[1]);
    mi = 2;
    minus -= 2;
    plus = 1;
  } else if (minus == 0) {
    if (plus == 2) {
      cout << pA[1] - pA[0] << endl;
      cout << pA[1] << " " << pA[0] << endl;
      return 0;
    }
    abs_sum -= (2 * pA[0]);
    cout << abs_sum << endl;
    cout << pA[0] << " " << pA[1] << endl;
    mA.emplace_back(pA[0] - pA[1]);
    pi = 2;
    plus -= 2;
    minus = 1;
  } else {
    cout << abs_sum << endl;
  }

  while (plus && minus) {
    if (plus <= minus) {
      cout << pA[pi] << " " << mA[mi] << endl;
      pA[pi] -= mA[mi++];
      --minus;
    } else {
      cout << mA[mi] << " " << pA[pi] << endl;
      mA[mi] -= pA[pi++];
      --plus;
    }
  }
  return 0;
}
