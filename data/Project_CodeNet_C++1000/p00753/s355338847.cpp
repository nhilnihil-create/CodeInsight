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

bool prime[123456 * 2 + 10];
short ans[123456 * 2 + 10];
void hurui(){
  prime[0] = prime[1];
  for(int i = 2;i <= 123456 * 2;i++){
    if(!prime[i]){
      for(int j = 2;i * j <= 123456 * 2;j++)prime[i * j] = true;
    }
  }
  lep(i,1,123456 * 2)ans[i] = ans[i-1] + int(!prime[i]);
}

int main(){
  clr(prime,false);
  clr(ans,0);
  hurui();
  while(1){
    cin >> n;
    if(!n)break;
    print(ans[n * 2] - ans[n]);
  }
  return 0;
}
