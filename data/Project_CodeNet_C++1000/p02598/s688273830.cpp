#pragma GCC optimize("Ofast")
#include  "bits/stdc++.h"
using namespace std;
#define I_AM_SPEED  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define printclock  cerr <<"Time : "<<(double)clock()/(double)CLOCKS_PER_SEC<<" sec\n";
#define mp(a , b)   make_pair(a , b)
#define eb(a)       emplace_back(a)
#define SZ(n)       ((int)(n).size())
#define all(n)      (n).begin(), (n).end()
#define anal           '\n'
#define mod         1000000007
#define fst         first
#define sec         second
#define pr(n)       cerr << n  << " ";
#define pfor(a)     for(auto (w) : (a)) pr(w)
//const double PI = acos(-1.0);
typedef long long ll;
typedef unsigned long long ull;

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-



//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
int main(){
I_AM_SPEED;
#ifndef ONLINE_JUDGE  
        freopen("input.in", "r", stdin);
        freopen("output.in", "w", stdout);
#endif 
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
     
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  ll l = 1, r = *max_element(all(a));
  while(l < r){
      ll mid = l + (r - l)/2;
      bool chk = true;
      ll cut = 0;
      for(int i = 0; i < n; i++){
          cut += (a[i] - 1)/mid ;
          if(cut > k){
              chk = false;
              break;
          }
      }
      if(chk) r = mid;
      else l = mid + 1;
  }  
  cout << l << anal;  

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//printclock; 
return  0 ;      
}        



      