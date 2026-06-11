#include<iostream>
#include<queue>
#include<deque>
#include<stdio.h>

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
typedef  long long ll;	
typedef long double ld;
typedef unsigned long long ull;
typedef  pair< long long , pair< int,int> > iii;

 
const int MAX = 1010;
 
 

using namespace std;





int  n, m, k;

char a[MAX][MAX];
int line[MAX], col[MAX];
 
int main () {
  
  //~ in
  scanf("%d %d %d",&n,&m, &k);
  
  int tot = 0;
  for(int i = 0 ;i  < n;i++) {
    scanf("%s", a[i]);
  }
  
  for(int i = 0 ;i < n;i++) {
    for(int j = 0 ;j < m;j++) {
      tot += a[i][j] == '#';
    }
  }
  
  int ans = 0;
  
  for(int i = 0;i < (1 << n);i++) {
    for(int j = 0 ;j < ( 1 << m) ;j++) {
      
      int num = 0;
      
      for(int s = 0 ;s < n ;s++) {
        for(int y = 0 ; y < m ;y ++) {
          if ( a[s][y] == '#' ){
            bool l = ( 1 << s ) & i;
            bool c = ( 1 << y ) & j;
            
          
            if ( c||l ) {
              num++;
              
              
            }
          }
        }
      }
 
      if ( tot-num == k ) {
  
        ++ans;
      }
    }
  }
  
  printf("%d\n", ans );
  
  return 0;
}


