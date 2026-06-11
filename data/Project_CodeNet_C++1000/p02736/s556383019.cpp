#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using ULL = uint64_t;
using P = pair<LL, LL>;
#define rep(i, n) for (LL i = 0; i < (n); ++i)
//#define DEBUG

//LL combination(const LL m, const LL n) {
//  LL prod = static_cast<LL>(1);
//  for (LL i = 0; i < n; ++i) {
//    prod *= (m - i);
//    prod /= (i + 1);
//  }
//  return prod;
//}

vector<LL> how_many_psum; // partial sum.

inline LL n_div_2(LL n) {
  LL count = 0;
  while (n != 0 && n % 2 != 1) {
    count++;
    n /= 2;
  }
  return count;
}

LL combination_mod_2(const LL m, const LL n) {
  if (how_many_psum.at(m) - how_many_psum.at(m - n) - how_many_psum.at(n) >= 1) {
    return 0;
  } else {
    return 1;
  }
}

int main() {
  LL n;
  cin >> n;

  string s;
  cin >> s;

  bool contains_mid = false;
  rep (i, n) {
    switch (s[i]) {
    case '1':
      s[i] = '0';
      break;
    case '2':
      s[i] = '1';
      contains_mid = true;
      break;
    case '3':
      s[i] = '2';
      break;
    }
  }

  if (!contains_mid) {
    rep (i, n) {
      switch (s[i]) {
      case '2':
        s[i] = '1';
        break;
      }
    }
  }

  how_many_psum.assign(n, 0);
  how_many_psum.at(0) = n_div_2(0);
  rep (i, n - 1) {
    how_many_psum.at(i + 1) = how_many_psum.at(i) + n_div_2(i + 1);
  }

  LL sum = 0;
  rep (i, n) {
    if (s[i] == '1') {
      sum += combination_mod_2(n - 1, i);
    }
  }
  if (sum % 2 != 1) {
    // mid value
    cout << '0' << endl;
  } else {
    if (contains_mid) {
      cout << '1' << endl;
    } else {
      cout << '2' << endl;
    }
  }
  
  #ifdef DEBUG
  cout << n << endl;
  cout << s << endl;
  #endif
}

