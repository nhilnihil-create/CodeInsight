#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
int n;
cin >> n;
map<string,int> mp;
vector<int> t(n);
rep(i,n){
  string s;
  int x;
  cin >> s >> x;
  mp[s]+=i;
  t.at(i) = x;
}
string a;
cin >> a;
int ans = 0;
for(int i = mp[a]+1; i < n; i++){
  ans += t.at(i);
}
cout << ans << endl;
}
