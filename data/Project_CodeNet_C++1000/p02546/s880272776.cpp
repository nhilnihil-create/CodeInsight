#include <bits/stdc++.h>
#include <vector>
#include <string.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
//#define INF 2e9
#define ALL(v) v.begin(), v.end()
 
using namespace std;
typedef long long ll;

int main(){
  string s;
  int slength;
  cin >> s ;
  if(s.back() == 's'){
    s += "es";
  }
  else{
    s += 's';
  }
  cout << s << endl;
  return 0;
}