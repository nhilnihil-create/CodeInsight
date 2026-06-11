// https://atcoder.jp/contests/abc177/tasks/abc177_e
#include <bits/stdc++.h>

using namespace std;

#define PVAR(x) (cout << #x"=" << x << endl)

// if all numbers share a prime factor      => not coprime
// if some but not all share a prime factor => setwise
// if no numbers share a prime factor       => pairwise
void test_case() {
  int n;
  cin >> n;
  vector<int> A(n);
  int ma = 0;
  for (int &a : A) {
    cin >> a;
    ma = max(ma, a);
  }

  // find prime factors
  vector<int> pfs(ma + 1);
  int pcount = 0;
  iota(pfs.begin(), pfs.end(), 0);
  for (int i = 2; i * i <= ma; i++) {
    if (pfs[i] == i) {
      pcount++;
      for (int j = i * i; j <= ma; j += i) {
        pfs[j] = i;
      }
    }
  }

  int cf = 0;
  bool pairwise_coprime = true;
  unordered_set<int> fs(pcount);
  for (int i = 0; i < n; i++) {
    int a = A[i];

    // if all numbers share common prime factors it is
    // the gcd over all numbers 
    cf = gcd(cf, a);

    // if a duplicate factor is found the set cannot
    // be pairwise coprime
    if (pairwise_coprime) {
      while (a > 1 && fs.find(pfs[a]) == fs.end()) {
        fs.insert(pfs[a]);
        int f = pfs[a];
        while (a % f == 0) a /= f;
      }

      pairwise_coprime = a == 1;
    }
  }

  // PVAR(common_factor);

  if (pairwise_coprime) {
    cout << "pairwise coprime" << endl;
  } else if (cf == 1) {
    cout << "setwise coprime" << endl;
  } else {
    cout << "not coprime" << endl;
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int i = 1;
  // cin >> i;
  while (i--) {
    test_case();
  }
  
  return 0;
}
