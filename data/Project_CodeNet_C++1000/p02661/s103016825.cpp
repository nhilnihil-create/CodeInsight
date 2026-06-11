#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
 
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

#define MOD 1000000007LL

int n;
vector<int> a, b;

int main()
{
  ll ans=0;

  cin >> n;
  a.resize(n); b.resize(n);
  for (int i=0; i<n; i++) {
    cin >> a[i] >> b[i];
  }
  sort(a.begin(), a.end()); sort(b.begin(), b.end());

  if (n%2) {
    ans = b[n/2] - a[n/2] + 1;
  } else {
    ans = (b[n/2]+b[n/2-1] - (a[n/2]+a[n/2-1])) + 1;
  }

  cout << ans << endl;
  return 0;
}

/*
  入力例2
  X1 = [100]
  X2 = [10, 11, ... , 10000]
  X3 = [1, 2, ... , 1000000000]
  */
