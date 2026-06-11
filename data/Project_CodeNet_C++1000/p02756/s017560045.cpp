#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
#define _GLIBCXX_DEBUG

int main() {
  string s; cin >> s;
  int n; cin >> n;
  int t,f;
  char c;
  string top,end;
  bool ord = true;;
  rep(i,n){
    cin >> t;
    if(t == 1) ord = !(ord);
    else{
      cin >> f;
      if(ord){
        if(f == 1){
          cin >> c;
          top = c+top;
        }
        if(f == 2){
          cin >> c;
          end = end+c;
        }
      }
      else{
        if(f == 2){
          cin >> c;
          top = c+top;
        }
        if(f == 1){
          cin >> c;
          end = end+c;
        }
      }

    }
  }

  s = top + s + end;
  if(!ord) reverse(s.begin(),s.end());
  cout << s << endl;

  return 0;
}
