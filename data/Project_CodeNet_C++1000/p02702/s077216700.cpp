#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  vector<int> a(2019,0);
  reverse(s.begin(),s.end());
  int now=0;
  int beki=1;
  a[0]++;
  rep(i,s.length()){
    int x=s[i]-'0';
    now+=beki*x;
    now%=2019;
    a[now]++;
    beki=beki*10%2019;
  }
  int ans=0;
  rep(i,2019){
    int x=a[i];
    ans+=(x*(x-1))/2;
  }
  cout << ans << endl;
}