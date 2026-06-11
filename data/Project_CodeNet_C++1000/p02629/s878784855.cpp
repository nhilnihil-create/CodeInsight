#include <bits/stdc++.h>
using namespace std;

int main() {
  unsigned long long N;
  cin >> N;
  /* 1, 26 */
  /* 26 + 1, 26 + 26**2 */
  /* 26**2 + 1, 26 + 26**2 + 26***3 */
  unsigned long long sum = 26;
  unsigned long long i = 1;
  while(true) {
    if(sum >= N) break;
    i++;
    sum += pow(26, i);
  }
  /* N -= 1; */
  string ans;
  string alp = "abcdefghijklmnopqrstuvwxyz";
  unsigned long long tmp = 0;
  for (unsigned long long j = 0; j < i; j++) {
    tmp = (N - 1) % 26;
    ans.insert(ans.begin(), alp[tmp]);
    N = (N - tmp) / 26;
  }
  cout << ans << endl;
  return 0;
}
