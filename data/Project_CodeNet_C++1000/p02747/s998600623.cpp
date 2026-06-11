#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define yorn(f) puts((f)?"Yes":"No")
#define YORN(f) puts((f)?"YES":"NO")
ll k;
//ld ;
string s;
// char c;

int main() {
  cin >> s;
  bool flg = true;
  if((s.length()%2)!=0){
    flg = false;
  }else{
    for(ll i=0; i<s.length()/2; i++){
      if(s[2*i]!='h' || s[2*i+1]!='i'){
        flg = false;
      }
    }
  }
  yorn(flg);
  return 0;
}