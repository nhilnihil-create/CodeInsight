#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MOD=1000000007;

int main() {
  string s;
  cin >> s;
  int n=s.size();
  vector<int> a(n);
  int cnt=0;
  rep(i,n-1) {
    while(s[i]=='R') {
      cnt++;  i++;
    }
    a[i-1]+=(cnt+1)/2;
    a[i]+=cnt/2;
    cnt=0;
  }
  for(int j=n-1; j>0; j--) {
    cnt=0;
    while(s[j]=='L') {
      cnt++; j--;
    }
    a[j]+=cnt/2;
    a[j+1]+=(cnt+1)/2;
    cnt=0;
  }
  rep(i,n) cout << a[i] << " ";
  cout << endl;
  return 0;
}