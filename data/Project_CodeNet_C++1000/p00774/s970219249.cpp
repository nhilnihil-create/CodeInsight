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
int field[200][200];

int main(){
  while(1){
    cin >> n;
    if(!n)break;
    clr(field,0);
    rep(i,0,n)rep(j,0,5)cin >> field[i][j];
    ll ans = 0;
    bool f = true;
    while(f){
      f = false;
      rep(i,0,n){
        rep(j,0,5){
          l = 1;
          rep(k,j,5){
            if(field[i][k] == 0)break;
            if(field[i][k] != field[i][k+1])break;
            l++;
          }
          if(l >= 3){
            f = true;
            rep(k,j,j+l){
              ans += field[i][k];
              field[i][k] = 0;
            }
          }
        }
      }
      // rep(i,0,n){
      //   rep(j,0,5)cout << field[i][j];
      //   puts("");
      // }
      // puts("");
      pel(i,n-1,0){
        rep(j,0,5){
          if(!field[i][j]){
            // cout << i << " " << j << endl;
            l = 0;
            pel(k,i,0){
              if(!field[k][j])l++;
              else break;
            }
            rep(k,0,n-i){
              if(i - k < 0)break;
              if(i - k - l< 0)break;
              field[i-k][j] = field[i-k-l][j];
              field[i-k-l][j] = 0;
            }
          }
        }
      }
      // rep(i,0,n){
      //   rep(j,0,5)cout << field[i][j];
      //   puts("");
      // }
      // puts("===================================");
    }
    print(ans);
  }
  return 0;
}
