#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;



int main(){
  string s;
  cin >> s;
  int q;
  cin >> q;

  bool isfor = true;
  string pre = "";
  string back = "";

  cout << pre << " " << back;

  REP(i,q){
    int t;
    cin >> t;
    if(t == 1) isfor = !isfor;

    if(t == 2){
      int f;
      char c;
      cin >> f >> c;

      if(isfor){
        if( f == 1) pre += c;
        if( f == 2) back += c;
      }
      else{
        if( f == 1) back += c;
        if( f == 2) pre += c;
      }
    }
  }

  string ans;

  if(isfor){
    reverse(ALL(pre));
    ans = pre + s + back;
  }
  else{
    reverse(ALL(back));
    reverse(ALL(s));
    ans = back + s + pre;
  }

  cout << ans << endl;


  return 0;
}
