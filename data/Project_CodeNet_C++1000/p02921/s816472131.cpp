#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long int;
using namespace std;
ll mod=1e9+7;


int main() {
  string s,t;
  int ans=0;
  cin >> s >> t;
  int a=s.size();
  rep(i,a){if(s[i]==t[i])ans++;}
  cout << ans << endl;
}