// {{{ include and macros
#define debug(x) cout<<#x<<": "<<x<<endl
#define rep(i, a, b) for(int i=a; i < b;i++)
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <deque>
using namespace std;
// }}}

// {{{ io
void newline() {cout << endl;}
template <typename T>
void display(T input){cout << input;}
template <typename T>
void put(T input){display(input); newline();}
  // }}}

deque<string> v;

int solve(){
  int cnt=0;
  bool r=false, l=false;
  string prev=v.front();
  v.pop_front();
  while(!v.empty()){
    string now=v.front();
    v.pop_front();
    if(prev=="lu" && now=="ru" || prev=="ru" && now=="lu"){cnt++;}
    if(prev=="ld" && now=="rd" || prev=="rd" && now=="ld"){cnt++;}
    prev=now;
  }
  return cnt;
}

int main() {
  int n;
  while(cin >> n && n){
    rep(i, 0, n){
      string s; cin >> s;
      v.push_back(s);
    }
    put(solve());
  }
}