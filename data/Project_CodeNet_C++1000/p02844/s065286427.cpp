#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans=0;
  for(int i=0; i<1000; i++) {
    int c[3]={i/100,i/10%10,i%10};
    int num=0;
    for(int j=0; j<n; j++) {
      if(s[j]=='0'+c[num]) num++;
      if(num==3) break;
    }
    if(num==3) ans++;
  }
  cout << ans << endl;
  return 0;
}