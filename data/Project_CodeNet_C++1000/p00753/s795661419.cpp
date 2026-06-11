#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back 
#define pf push_front 
#define mp make_pair
#define fr first
#define sc second
#define Rep(i,n) for(int i=0;i<(n);i++)
#define All(v) v.begin(),v.end()
typedef pair<int, int> Pii; typedef pair<int, Pii> Pip;
const int INF = 1107110711071107;

main()
{
  int n;
  int isprime[2*123457];

  fill_n(isprime, 2*123457, 1);
  
  for(int i=2; i<2*123457; i++) {
    for(int j=2; i*j<2*123457; j++) {
      isprime[i*j] = 0;
    }
  }
  
  while( cin >> n, n ) {
    int ans = 0;
    for(int i=n+1; i<=2*n; i++) {
      if( isprime[i] ) ans++;
    }

    cout << ans << endl;
  }
}