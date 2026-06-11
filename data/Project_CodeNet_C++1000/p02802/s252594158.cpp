#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000000
#define endl "\n"
#define PI 3.14159265358979323846264338327950288

using namespace std ;
using bigint = long long int ;
using vi = vector<int> ;
using vll = vector<long long int> ;


int main(){
    FAST_IO ;
    int N , M ; cin >> N >> M ;
    map<int , int> AC , WA ;
    int ac = 0 , wa = 0 ;
    for( int i = 0 ; i < M ; i++ ){
        int p ; cin >> p ;
        string str ; cin >> str ;
        if( str == "AC" && AC[p] == 0 ){
            AC[p]++ ;
            ac++ ;
            wa += WA[p] ;
        }
        else{
            WA[p]++ ;
        }
    }
    cout << ac << " " << wa << endl ;
    return 0 ;
  }










// dp[x] = represents the expected value of steps to get gcd = 1 when current gcd = x


// Exepected Value  = 1 + sigma ( dp[i] / M ) from i = 1 to M ;

// 001
// 110
// 011
// 100
//1 2 3 4
//1 0 3 0
//



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

























