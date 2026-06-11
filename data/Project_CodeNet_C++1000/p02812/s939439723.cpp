#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
  int n;
  string s;
  cin >> n >> s;
  int cnt = 0;
  rep(i,n-2) {
    if (s.substr(i,3) == "ABC") cnt++;
  }
  cout << cnt << endl;
}
