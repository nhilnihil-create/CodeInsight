#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include <stdio.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define vec vector
#define ref(a) &(a)

typedef long long ll;

using namespace std;

int n;

int solve() {
  return (n - 1) / 2;
}

int main() {
  cin >> n;
  cout << solve() << endl;
  return 0;
}