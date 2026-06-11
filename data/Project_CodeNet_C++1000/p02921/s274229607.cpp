#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); ++i)


int main() {
  string a,b;
  cin>>a>>b;
  int ans=0;
  REP(i,3)ans+=a[i]==b[i]; 
  cout << ans << endl;
}