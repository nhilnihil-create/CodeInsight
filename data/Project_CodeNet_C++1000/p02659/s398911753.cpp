#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)

int main() {
  long long a;cin>>a;
  double b;cin >>b;
  long long bl = 100*b+0.0001;
  long long c = (a*bl)/100;
  cout << c << endl;
  return 0;
}