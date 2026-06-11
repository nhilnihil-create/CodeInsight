#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  string s;
  cin >> s;
  int n = s.length();

  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    int val = s[i] - '0';
    if (val < 10 - val) {
      ans += val;
    } else if (val == 5 && (i == 0 || s[i - 1] < '5')) {
      ans += val;
    } else {
      ans += 10 - val;
      int j = i - 1;
      while (j >= 0 && s[j] == '9') {
        s[j] = '0';
        j--;
      }
      if (j == -1){
        ans++;
        break;
      }
      else s[j]++;
    }
  }

  cout << ans << '\n';
}
