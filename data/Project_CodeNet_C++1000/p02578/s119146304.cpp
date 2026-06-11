#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define endl "\n"
#define PI 3.14159265358979323846264338327950288

using namespace std ;
using bigint = long long int ;
using vi = vector<int> ;
using vll = vector<long long int> ;


int main(){
    FAST_IO ;
    int N ; cin >> N ;
    int arr[N+1] ;
    for( int i = 0 ; i < N ; i++ )
        cin >> arr[i] ;
    bigint ans = 0 ;
    int curr_max = arr[0] ;
    for( int i = 0 ; i < N ; i++ ){
        curr_max = max( curr_max , arr[i] ) ;
        ans = ans + curr_max - arr[i] ;
    }
    cout << ans << endl ;
    return 0 ;
  }





// dp[x] = represents the expected value of steps to get gcd = 1 when current gcd = x


// Exepected Value  = 1 + sigma ( dp[i] / M ) from i = 1 to M ;

// 001
// 110
// 011
// 100


 



//
//string str ; cin >> str ;
//   int N ; cin >> N ;
//   unordered_set<string> s ;
//   for( int i = 0 ; i < N ; i++ ){
//       string x ; cin >> x ;
//       s.insert(x) ;
//   }
//   dp[0] = 0 ;
//   int L = ( int ) str.length() ;
//   dp[L] = 1 ;
//   for( int i = L - 1 ; i >= 0 ; i-- ){
//       string word ;
//       for( int j = i ; j < L ; j++ ){
//           word.push_back(str[j]) ;
//           if( s.find(word) != s.end() && dp[j+1] != 0 )
//               dp[i] = dp[j+1] ;
//       }
//   }
//   cout << dp[0] << endl ;









