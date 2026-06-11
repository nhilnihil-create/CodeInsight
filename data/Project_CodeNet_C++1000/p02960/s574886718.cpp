#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  vector<long> a(13);
  vector<long> b(13);
  vector<long> c={1,10,9,12,3,4};
  cin >> s;
  long x=0;
  for(long i=s.size()-1;i>=0;i--) if(s[i]!='?') x=(x+(s[i]-'0')*c[(s.size()-i-1)%6])%13;
  a[x]=1;
  for(long i=s.size()-1;i>=0;i--) {
    if(s[i]=='?') {
      b=a;
      for(long i2=0;i2<13;i2++) {
        for(long i3=1;i3<10;i3++) {
          a[(i2+i3*c[(s.size()-i-1)%6])%13]+=b[i2];
          a[(i2+i3*c[(s.size()-i-1)%6])%13]=a[(i2+i3*c[(s.size()-i-1)%6])%13]%1000000007;
        }
      }
    }
  }
  cout << a[5] << endl;
}