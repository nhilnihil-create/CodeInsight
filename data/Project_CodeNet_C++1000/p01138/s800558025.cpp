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
  while( cin >> n, n ) {
    int cnt[100000] = {0};
    
    while( n-- ) {
      int st, en;
      int h, m, s;
      
      scanf("%lld:%lld:%lld", &h, &m, &s);
      st = h*3600 + m*60 + s;
      
      scanf("%lld:%lld:%lld", &h, &m, &s);
      en = h*3600 + m*60 + s;

      for(int i=st; i<en; i++) cnt[i]++;
    }

    int ma = 0;
    for(int i=0; i<100000; i++) ma = max( ma, cnt[i] );

    cout << ma << endl;
    
  }
  
}