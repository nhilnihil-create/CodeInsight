// Mon Aug 24 16:24:09 IST 2020        
#include <bits/stdc++.h>        
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define forn(ii,a,b)       for(int ii = (int)a ; ii < (int)b  ; ii++ )
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
const int N = 2e5+7;
struct compare{
    bool operator()(pair <int,int> A, pair <int,int> B){
        if(A.first == B.first)
            return A.second > B.second;
        return A.first > B.first;
    }
}; 
void print(vector <int>v){
    for(int t : v){
        cout << t << ' ';
    }
    cout << '\n';
}
int tests(){  
    int A,B,C,K;
    cin >> A >> B >> C >> K;
    if(K <= A)
        return cout << K << '\n',0;
    if(K <= B)
        return cout << A << '\n',0;
    cout << A-(K-(A+B)) << '\n';
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
 