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
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define sz size()
#define print(X) cout << (X) << endl
static const int INF = 1e+9+7;
ll n,m,l;
string s,t;
int d[200010],dp[1010][1010];
double w[1000],v[1000];
double box[200010];
char field[200][200];

int main(){
  while(1){
    getline(cin,s);
    if(s == ".")break;
    t = "";
    vc vec;
    rep(i,0,s.sz){
      if(s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']')vec.pb(s[i]);
    }
    string ans = "yes";
    if(vec.sz % 2)ans = "no";
    else{
      while(1){
        bool f = true;
        if(vec.empty())break;
        rep(i,0,vec.sz-1){
          if((vec[i] == '(' && vec[i+1] == ')') || (vec[i] == '[' && vec[i+1] == ']')){
            f = false;
            vec.erase(vec.begin() + (i));
            vec.erase(vec.begin() + (i));
            break;
          }
        }
        if(f){
          ans = "no";
          break;
        }
      }
    }
    print(ans);
  }
  return 0;
}
