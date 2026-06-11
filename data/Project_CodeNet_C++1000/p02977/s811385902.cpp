#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;

int main()
{
  int n;
  cin>>n;
  if (__builtin_popcount(n) == 1) {
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  if ((n%2) == 0) {
    FOR(i,2,n) {
      cout<<i<<' '<<1<<endl;
      cout<<i<<' '<<(n+(i^1))<<endl;
    }
    cout<<n*2-1<<' '<<n+1<<endl;
    int bit = n & ~(n-1);
    cout<<n<<' '<<(n^bit)<<endl;
    cout<<n*2<<' '<<(bit^1)<<endl;
  } else {
    FOR(i,2,n+1) {
      cout<<i<<' '<<1<<endl;
      cout<<i<<' '<<(n+(i^1))<<endl;
    }
    cout<<n*2<<' '<<n+1<<endl;
  }
  return 0;
}
