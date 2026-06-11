#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
  vector<int> A(101);
  rep(i, 9) {
    int a;
    cin >> a;
    A[a] = i + 1;
  }

  int n;
  cin >> n;
  vector<int> cnt(10);
  rep(i, n) {
    int b;
    cin >> b;
    cnt[A[b]]++;
  }

  if(cnt[1] + cnt[2] + cnt[3] == 3 || cnt[4] + cnt[5] + cnt[6] == 3 ||
     cnt[7] + cnt[8] + cnt[9] == 3 || cnt[1] + cnt[4] + cnt[7] == 3 ||
     cnt[2] + cnt[5] + cnt[8] == 3 || cnt[3] + cnt[6] + cnt[9] == 3 ||
     cnt[1] + cnt[5] + cnt[9] == 3 || cnt[3] + cnt[5] + cnt[7] == 3)
    cout << "Yes";
  else
    cout << "No";
}
