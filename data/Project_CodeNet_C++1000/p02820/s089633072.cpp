#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

int main() {
ll n,k,r,s,p;
string t;
cin >> n >> k;
cin >> r >> s >> p;
cin >> t;
ll ans = 0;
string a;
rep(i,k) {
  if (t[i] == 'r') {
    ans += p;
    a.push_back('p');
  } else if (t[i] == 's') {
    ans += r;
    a.push_back('r');
  } else if (t[i] == 'p') {
    ans += s;
    a.push_back('s');
  }
}
for (int i = k;i < n;i++) {
  if (t[i] == 'r') {
    if(a[i-k] != 'p') {
    ans += p;
    a.push_back('p');
    } else a.push_back('a');
  } else if (t[i] == 's') {
    if (a[i-k] != 'r') {
    ans += r;
    a.push_back('r');
    } else a.push_back('a');
  } else if (t[i] == 'p') {
    if (a[i-k] != 's') {
    ans += s;
    a.push_back('s');
    } else a.push_back('a');
  }
}

cout << ans << endl;
return 0;
}

