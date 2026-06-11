/**
 *    author:  math2do
 *    created: 30.08.2020 16:50:37
**/

#include <bits/stdc++.h>

using namespace std;

vector <char> arr = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  string ans;
  while (n > 0) {
    int d = (int) ((n - 1) % 26);
    char ch = arr[d];
    ans += ch;
    n = (n - 1) / 26;
  } 
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
