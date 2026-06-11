#include <bits/stdc++.h>


using namespace std;
using ll = long long;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto& x : a) cin >> x;
    sort(begin(a), end(a));
    int res = 0;
    for(int i = 0; i < k; i++) {
      res += a[i];
    }
    cout << res << "\n";



  return 0;
}

