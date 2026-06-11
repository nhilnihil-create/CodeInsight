#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,p,ans=0;
  string s;
  cin >> n >> p >> s;
  vector<long> a(n+1);

  a[0]=0;
  long j=1;
  for (long i = n - 1; i >= 0; i--) {
    a[n-i]=((s[i]-'0')*j+a[n-i-1])%p;
    j=j*10%p;
  }
  sort(a.begin(),a.end());
  j=1;
  for(long i=1;i<n+1;i++) {
    if(a[i]==a[i-1]) {
      ans+=j;
      j++;
    } else {
      j=1;
    }
  }
  if(p==2||p==5) {
    ans=0;
    for(long i=0;i<n;i++) if((s[i]-'0')%p==0) ans+=i+1;
  }
  cout << ans << endl;
}