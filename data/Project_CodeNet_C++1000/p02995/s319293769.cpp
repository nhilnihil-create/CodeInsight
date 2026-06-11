#include <bits/stdc++.h>
using namespace std;

int main() {
  long A,B;cin>>A>>B;
  long C,D;cin>>C>>D;
  long ans=0;
  ans += B/C;
  ans += B/D;
  ans -= (A-1)/C;
  ans -= (A-1)/D;
  long S=gcd(C,D);
  ans -= ((B/C)*S)/D;
  ans += (((A-1)/C)*S)/D;
  cout<<B-A+1-ans<<endl;
}
