// 4/3/2020 8:00:11 PM
#include <bits/stdc++.h>  
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
#define forn(i,a,b)        for( i = a ; i < b  ; i++ )
#define debug(x)           cout << #x << " " << x << " -- \n"
#define I__O               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll                 long long    
#define MOD                998244353
#define pi                 pair<int,int>
#define vi                 vector <int>
#define pb                 push_back
#define vp                 vector <pair<ll,ll>>
#define endl               cout << "\n"  
#define f1                 first 
#define s1                 second    
#define in                 insert
#define all(x)             (x).begin(),(x).end() 
using namespace std ; 
// 2020-04-01
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,
// rb_tree_tag,tree_order_statistics_node_update> indexed_set ; 
const int N = 2e5+20;
const int mod = 1e9+7;  
bool is(char c ){
  return c > '0' && c <= '9';
}
int tests() {
  ll s ;
  cin >> s ; 
  cout << 0 << ' ' << 0 << ' ' ;
  ll x1,y1 ;
  x1 = 1e9,y1 =1 ;
  cout << y1 << ' ' << x1 << ' ' ;
  cout << (s+x1-1)/x1 << ' ' << (x1-s%x1)%x1 << '\n';
  return 0;
} 
int main(){
    I__O ;            
    int cases = 1 ; 
    // cin >> cases ;  
    for(int  _ = 1 ; _ <= cases ; _++ ){   
    // cout << "Case #" << _ << ": ";
      tests(); 
    }
    return 0 ; 
}

// -Wall -Weptra -O2
// -pedantic -std=c++11
// -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
