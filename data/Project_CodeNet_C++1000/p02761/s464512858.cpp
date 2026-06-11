#include<bits/stdc++.h>
using namespace std;

#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

#define forn(n) for(int i = 0; i < n; i++)
#define fork(k, n) for(int i = k; i < n; i++)

#define pb(n) push_back(n);

typedef long long ll;
typedef double dbl;

const int MX = 1e6;
const int MOD = 1e9 + 7;
const string ALPHA = "abcdefghijklmnopqrstuvwxyz";
const double PI = 3.1415926535;

int main(){
  int n, m;
  cin>>n>>m;
  map<int, int> occ;
  bool bad = 0;
  while(m--){
    int s, c;
    cin>>s>>c;
    if(occ.count(s) && occ[s] != c){
      bad = 1;
      break;
    } else if(s == 1 && c == 0 && n > 1){
      bad = 1;
      break;
    } else {
      occ[s] = c;
    }
  }
  if(bad){
    cout<<-1<<endl;
  } else {
    int p = 1;
    while(p <= n){
      if(occ.count(p)){
        cout<<occ[p];
      } else {
        if(p == 1 && n > 1){
          cout<<"1";
        } else {
          cout<<"0";
        }
      }
      p++;
    }
    cout<<"\n";
  }
}
