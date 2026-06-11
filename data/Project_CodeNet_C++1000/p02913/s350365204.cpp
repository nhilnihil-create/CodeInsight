#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0;
  string s;
  cin >> n >> s;
  for(long i=1;i<n;i++) {
    long a=0;
    for(long j=0;i+j<n;j++) {
      if(i==a) a--;
      if(s[j]==s[i+j]) a++;
      else a=0;
      ans=max(ans,a);
    }
  }
  cout << ans << endl;
}