#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> a(N);
  rep(i,0,N-1) cin >> a[i];

  sort(a.begin(), a.end());

  if (a[N-1] == 0)
    cout << "Yes" << endl;
  else if (N % 3 == 0)
  {
    if (a[0] == 0 && a[N / 3 - 1] == 0 && a[N / 3] == a[N - 1])
      cout << "Yes" << endl;
    else if (a[0] == a[N / 3 - 1] && a[N / 3] == a[2 * N / 3 - 1] && a[2 * N / 3] == a[N - 1] && (a[0] ^ a[N / 3] ^ a[2 * N / 3]) == 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  else
    cout << "No" << endl;
  
  return 0;
}
