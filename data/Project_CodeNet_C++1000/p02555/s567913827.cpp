// Mon Sep 14 19:59:49 IST 2020  


#include <bits/stdc++.h>        
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define forn(ii,a,b)       for(int64 ii = (int64)a ; ii < (int64)b  ; ii++ )
#define scan(any)          for(auto &i:any) cin>>i;
#define debug(x)           cerr << #x << " " << x << " -- \n"
#define I__O               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define int64              long long   
#define all(x)             (x).begin(),(x).end() 
#define ff                 first
#define ss                 second
#define pppp               pair <int,int> 
#define flushOff           fflush(stdout) 
#define precise(x)         cout << fixed << setprecision(12) << x << '\n'; 
using namespace std ;    
// policy based   
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set ; 
 
const int MOD1 = 1e9+7;
const int MOD2 = 1e9+9;
const double pi = 3.141592653589793238;
const int INF = 2e9+7;
const int64 big = INT64_MAX;

const int N = 2e5+7;
struct compare{
    bool operator()(pair <int,int> A, pair <int,int> B){
        if(A.first == B.first)
            return A.second > B.second;
        return A.first > B.first;
    }
}; 
void print(vector <int>v){
    for(int t : v) 
        cout << t << ' ';
    cout << '\n';
    return;
}
void printSet(multiset <int>v){
    cout << "===\n";
    for(int t : v) 
        cout << t << ' ';
    cout << '\n';
    return;
}
int dp[2020];
int solve(int n){
    if(dp[n])
      return dp[n] ;
    int ways  = 1;
	for(int i = 3 ; i < n ; i ++)
      if(n-i > 2)
        ways = (ways + solve(n-i))%MOD1;
    
    return dp[n] = ways;
}
int tests(){ 
  int x;
  cin >> x;
  if(x < 3)
    return cout << 0 << '\n',0;
  cout << solve(x) << '\n';
    return 0;
}    
int main(){
    I__O ;      
    int cases = 1 ;  
    // cin >> cases ;
    while(cases--)
        tests(); 
    return 0 ; 
}
 
