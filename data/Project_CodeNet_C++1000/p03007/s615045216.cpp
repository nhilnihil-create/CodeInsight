#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll A[N];
  vector<ll> plus;
  vector<ll> minus;
  ll min_abs = 999999;
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    sum += abs(A[i]);
    min_abs = min(min_abs,abs(A[i]));
    if (A[i] >= 0) {
      plus.push_back(A[i]);
    } else {
      minus.push_back(A[i]);
    }
  }

  if ((int)plus.size() == N || (int)minus.size() == N) {
    cout << sum - (min_abs * 2) << endl;
    if ((int)plus.size() == N) {
      sort(plus.begin(),plus.end());
      for (int i = 1; i < (int)plus.size() - 1; i++) {
        cout << plus[i-1] << " " << plus[i] << endl;
        plus[i] = plus[i-1] - plus[i];
      }
      cout << plus[plus.size() - 1] << " " << plus[plus.size() - 2] << endl;
    } else {
      sort(minus.begin(),minus.end());
      reverse(minus.begin(),minus.end());
      for (int i = 1; i < (int)minus.size() - 1; i++) {
        cout << minus[i-1] << " " << minus[i] << endl;
        minus[i] = minus[i-1] - minus[i];
      }
      cout << minus[minus.size() - 2] << " " << minus[minus.size() - 1] << endl;
    }
  } else {
    cout << sum << endl;
    swap(plus[0],minus[0]);
    for (int i = 1; i < (int)plus.size(); i++) {
      cout << plus[i-1] << " " << plus[i] << endl;
      plus[i] = plus[i-1] - plus[i]; 
    }
    for (int i = 1; i < (int)minus.size(); i++) {
      cout << minus[i-1] << " " << minus[i] << endl;
      minus[i] = minus[i-1] - minus[i];
    }
    cout << minus[(int)minus.size() - 1] << " " << plus[(int)plus.size() - 1] << endl;
  }
  return 0;
}