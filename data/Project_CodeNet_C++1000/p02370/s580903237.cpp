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
#define fprint(NUM,X) cout << fixed << setprecision(NUM) << (X) << endl
#define fprints(NUM,X,Y) cout << fixed << setprecision(NUM) << (X) << " " << (Y) << endl
const ll INF = 1e+9+7;
ll n,m,l;
string s,t;
ll d[200010],dp[550][550];
double w[1000],v[1000];
double box[200010];
static const int MAX = 100000;
static const int INFTY = (1 << 29);

vector<int> G[MAX];
list<int> out;
bool V[MAX];
int N;
int indeg[MAX];

void dfs(int s){
  queue<int> que;
  que.push(s);
  V[s] = true;
  while(!que.empty()){
    int u = que.front();que.pop();
    out.push_back(u);
    for(int i = 0;i < G[u].size();i++){
      int v = G[u][i];
      indeg[v]--;
      if(indeg[v] == 0 && !V[v]){
        V[v] = true;
        que.push(v);
      }
    }
  }
}

void tsort(){
  for(int i = 0;i < N;i++){
    indeg[i] = 0;
  }
  for(int u = 0;u < N;u++){
    for(int i = 0;i < G[u].size();i++){
      int v = G[u][i];
      indeg[v]++;
    }
  }
  for(int u = 0;u < N;u++)
    if(indeg[u] == 0 && !V[u])dfs(u);

  for(list<int>::iterator it = out.begin(); it != out.end();it++){
    cout << *it << endl;
  }
}

int main(){
  int p,q,M;
  cin >> N >> M;
  for(int i = 0;i < N;i++)V[i] = false;
  for(int i = 0;i < M;i++){
    cin >> p >> q;
    G[p].push_back(q);
  }

  tsort();
  return 0;
}
