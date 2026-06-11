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
  int isprime[1000001];
  
  fill_n(isprime, 1000001, 1);
  isprime[0] = isprime[1] = 0;
  
  for(int i=2; i<1000001; i++) {
    for(int j=2; i*j<1000001; j++) {
      isprime[i*j] = 0;
    }
  }
  
  
  int a, d, n;
  while( cin >> a >> d >> n, !(a == 0 && d == 0 && n == 0) ) {
    int cnt = 0;
    for(int i=0; ; i++) {
      if( isprime[a+i*d] ) cnt++;
      if( cnt == n ) {
	cout << a+i*d << endl;
	break;
      }
    }
  }
  
}