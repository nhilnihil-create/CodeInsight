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

int n ;


int gcd (int a, int b ){
  while ( b ) {
    int aux = b;
    b = a % b;
    a = aux;
  }
  return a;
}

int main () {
  //~ in
  fast_io
  
  cin >> n;
  
  bool parwise = true;
  int aux = 0;
  
  set <int> st;
  
  for(int i = 0 ;i < n;i++) {
    int x;
    cin >> x;
    
    if ( aux == 0 ){
      aux = x;
    }else {
      aux = gcd ( aux, x );
    }
    
    int N = x;
    for(int j = 2;j * j <= N && parwise ;j++) {
      
      if ( x % j == 0 ) {
        if (st.count ( j )) {
          parwise = 0;
        }
        st.insert ( j );
        while ( x % j == 0  && parwise){
          x/=j;
        }
      }
    }
    
    if ( x != 1 ){
      if (st.count ( x ) ) {
        parwise = false;
      }
      
      st.insert ( x);
    }
    
  }
  
  if ( parwise ) {
    cout << "pairwise coprime\n";
  }else if ( aux == 1  ){
    cout << "setwise coprime\n";
  }else  { 
    cout << "not coprime\n";
  }

    
  
  
  return 0;
}
