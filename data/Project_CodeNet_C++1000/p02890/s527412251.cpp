#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> vec;

const int N = 300030;
int A[N];
int P[N];
int ov[N];
int n;

int qu(int o) {
  int lo=0, hi=n;
  while (lo<hi) {
    int mid = (lo+hi+1)/2;

    if (mid != 0 && vec[mid-1] < o) {
      hi = mid-1;
    }
    else {
      lo = mid;
    }
  }

  int ans = lo+(P[n]-P[lo])/o;
  //cerr << " o = " << o << " :: " << ans << " ,, " << lo << " + (" << P[n] << "-" << P[lo] << ")/" << o << endl;
  return ans;
}

int solve(int k) {
  int lo = 0, hi = n;
  while (lo < hi) {
    int o = (lo+hi+1)/2;

    int va = ov[o];

    if (va < k) {
      hi = o-1;
    } else {
      lo = o;
    }
  }
  return lo;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i=1; i<=n; ++i) {
    int x;
    cin >> x;
    ++A[x];
  }
  for (int i=1; i<=n; ++i) {
    vec.push_back(A[i]);
  }
  sort(vec.rbegin(), vec.rend());
  for (int i=1; i<=n; ++i) {
    P[i] = P[i-1]+vec[i-1];
  }

  ov[0] = n;
  for (int i=1; i<=n; ++i) {
    ov[i] = qu(i);
  }
 
  for (int i=1; i<=n; ++i) {
    cout << solve(i) << "\n";
  }


  return 0;
}
