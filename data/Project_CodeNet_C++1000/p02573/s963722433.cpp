#include<iostream>
#include<queue>
#include<deque>
#include<vector>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
#include<map>
#include<bitset>
#include<unordered_set>
#include<unordered_map>
 
#define pi 3.141592653
#define in freopen("entrada","r",stdin);
#define out freopen("myfile.txt","w",stdout);
#define ii pair<int,int> 
#define fast_io cin.tie(0), cin.sync_with_stdio(false);
#define inf 0x3f3f3f3f
#define sup_inf 1e18
#define f first
#define s second
#define eps 1e-9

#define nl ( no << 1)
#define nr ( no << 1)|1
#define mid l+(( r-l)>>1)
 
using namespace std;
typedef long long ll;	
typedef long double ld;
typedef unsigned long long ull;
typedef  pair< long long , pair< int,int> > iii;

const int maxn = 2e5 + 100; 
const int MAX = 1010;
const int mod = 1e9 + 7;
const int MAXLV = 16;
 

using namespace std;



int an[maxn], sz[maxn];


int n, m , ans = 1;


int findc(int u ){
  while ( an[u] != u ){
    u = an[u] = an[an[u]];
  }
  return u;
}

void une ( int a, int b) { 
  
  int x = findc(a);
  int y = findc(b);
  if ( x == y) return;
  an[x] = y;
  sz[y]+=sz[x];
  ans = max ( sz[y], ans );
}



int main () { 
  
  
  //~ in
  fast_io
  cin >> n >> m;
  
  for(int i = 0 ;i < maxn;i++) { 
    an[i] = i;
    sz[i] = 1;
  }
  
  for(int i = 0 ;i < m;i++ ){ 
    int ai, bi;
    cin >> ai >> bi;
    une ( ai, bi);
  }
  
  
  
  cout << ans << '\n';
  
  
  
  return 0;
}
