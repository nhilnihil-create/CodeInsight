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
#define pfor(a)       for(auto (w) : (a)) pr(w)
//const double PI = acos(-1.0);
typedef long long ll;
typedef unsigned long long ull;

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

vector<int> v(26, -1);

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
      
int main(){
I_AM_SPEED;
#ifndef ONLINE_JUDGE  
        freopen("input.in", "r", stdin);
        freopen("output.in", "w", stdout);
#endif 

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
      
     
      int x;
      cin >> x;
      if(x >= 400 && x <= 599){
          cout << "8";
      }
      else if(x >= 600 && x <= 799){
          cout <<"7";
      }
      else if(x >= 800 && x <= 999){
          cout << "6";
      }
      else if(x >= 1000 && x <= 1199){
          cout << "5";
      }
      else if(x >= 1200 && x <= 1399){
          cout << "4";
      }
      else if(x >= 1400 && x <= 1599){
          cout << "3";
      }
      else if(x >= 1600 && x <= 1799){
           cout << "2";
      }
      else cout << "1";

        

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//printclock; 
return  0 ;      
}        



      