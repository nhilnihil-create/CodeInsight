#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
#define ll long long 
#define int long long 
#define vll vector<long long>
#define pii pair<long long ,long long > 
#define vvi vector< vector<long long > > 
#define vpii vector<pair<int,int>> 
#define pll  pair<long long ,long long > 
#define pb  push_back
#define ff  first 
#define sec second  
#define SORT(a) sort(a.begin(),a.end())
#define SORTR(a) sort(a.rbegin(),a.rend()) 
#define m_p make_pair
#define all(x) (x.begin(),x.end()) 
#define sz(v) ((int)(v.size()))
#define endl '\n'
typedef vector< long long > vi ;
const int MOD=1e9 +7 ;
int sizet=1e4+10; 
 
int recur( int h){ 

    if(h==1) return 1; 
    else return recur(h>>1)*2+1; 

}


int32_t main(){
  fast; 
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif 
    
  int T=1; //cin>>T; 
  while(T--){

     int h,n; cin>>h>>n; 
     vpii v(n); 
     for(int i=0;i<n;i++){ int x,y; cin>>x>>y; v[i]={x,y};} 

    vector< int> dp(sizet,INT_MAX);
    dp[h]=0; 
    for(int i=h;i>=0;i--){
        if(dp[i]!=INT_MAX){
            for(int j=0;j<n;j++){
                pii p=v[j]; 
                if(i-p.ff>=0) dp[i-p.ff]=min(dp[i-p.ff],dp[i]+p.sec); 
                else dp[0]=min(dp[0],dp[i]+p.sec);
            }
        }
    }  
    //debug(dp); 
    cout<<dp[0]<<endl; 




  }
    


  return 0; 
} 
