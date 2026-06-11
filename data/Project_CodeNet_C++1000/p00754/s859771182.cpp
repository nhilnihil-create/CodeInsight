#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
#include <exception>
#include <numeric>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<P> vp;
#define rep(i,a,n) for(ll i=(a); i<(n); ++i)
#define rrep(i,a,n) for(ll i=(a); i>(n); --i)
#define erep(i,a,n) for(ll i=(a); i<=(n); ++i)
#define rerep(i,a,n) for(ll i=(a); i>=(n); --i)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair
#define print(X) cout << (X) << endl
#define _ << " " <<
static const int INF = 1e+9+7;

int main(){
  while(true){
    str text;
    getline(cin, text);
    if(text[0] == '.') break;

    stack<char> c;
    bool flag = true;
    rep(i,0,text.size()){
      if(text[i] == '(') c.push('(');
      if(text[i] == '[') c.push('[');
      if(text[i] == ')'){
        if(c.empty()){
          flag = false;
          break;
        }
        if(c.top() == '(') c.pop();
        else{
          flag = false;
          break;
        }       
      }

      if(text[i] == ']'){
        if(c.empty()){
          flag = false;
          break;
        }
        if(c.top() == '[') c.pop();
        else{
          flag = false;
          break;
        }
      }
    }
  
    if(flag && c.empty()) print("yes");
    else print("no");
  }
  
  return 0;
}

