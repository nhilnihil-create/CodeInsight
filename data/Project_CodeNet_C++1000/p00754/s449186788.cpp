#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <tuple>
#include <complex>
#include <cassert>
#include <exception>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<P> vp;
#define rep(i,a,n) for(ll i = (a);i < (n);i++)
#define per(i,a,n) for(ll i = (a);i > (n);i--)
#define lep(i,a,n) for(ll i = (a);i <= (n);i++)
#define pel(i,a,n) for(ll i = (a);i >= (n);i--)
#define clr(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz size()
#define print(X) cout << (X) << "\n"
#define input(X) getline(cin,X)
static const int INF = 1e+9+7;
static const ll INFL = 1e+18+7;
ll n,m,l;
int p;
string s,t;
ll d[200010],dp[300][300];
char field[200][200];

vc split(string args){
  vc res;
  rep(i,0,args.sz){
    switch(args[i]){
      case '(':
      case ')':
      case '[':
      case ']':
        res.pb(args[i]);
        break;
      default:
        break;
    }
  }
  return res;
}

int main(){
  while(input(s),s != "."){
    stack<char> ans;
    vc vec = split(s);
    rep(i,0,vec.sz){
      if(vec[i] == '[' || vec[i] == '(')ans.push(vec[i]);
      else{
        if(ans.empty())ans.push(vec[i]);
        else if(vec[i] == ']'){
          if(ans.top() == '[')ans.pop();
          else ans.push(vec[i]);
        }else if(vec[i] == ')'){
          if(ans.top() == '(')ans.pop();
          else ans.push(vec[i]);
        }
      }
    }
    if(ans.empty())puts("yes");
    else puts("no");
  }
  return 0;
}
