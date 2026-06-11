#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;

int main() {
int n;
cin >> n;
vector<int> b(n-1);
vector<int> a(n);
rep(i,n-1) cin >> b.at(i);
a.at(0) = b.at(0);
a.at(n-1) = b.at(n-2);
for (int i = 1; i < n-1; i++) {
  if(b.at(i) <= b.at(i-1)) a.at(i) = b.at(i);
  else a.at(i) = b.at(i-1);
}
int ans = 0;
rep(i,n){
  ans += a.at(i);
}
cout << ans << endl;

}
