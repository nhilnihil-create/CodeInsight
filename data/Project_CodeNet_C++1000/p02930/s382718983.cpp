#include <bits/stdc++.h>
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define int long long
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
const int INF = 1010000000;
const double EPS = 1e-10;
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 

vector<int> init(int size){
  vector<int> par(size,-1);
  return par;
}

int root(int x, vector<int>& par){
  if(par[x] < 0){
    return x;
  }else{
    return par[x] = root(par[x],par);
  }
}

bool same(int x, int y, vector<int>& par){
  return root(x, par) == root(y, par);
}

void unite(int x, int y, vector<int>& par){
  x = root(x, par), y = root(y, par);
  if(same(x,y, par))return;
  par[x] += par[y];
  par[y] = x;
}

int size(int x, vector<int>& par){
  return -par[root(x, par)];
}

int pow(int x, int n){
  if(n == 0)return 1;
  if(n % 2 == 0)return pow(x * x % MOD, n/2);
  else return x * pow(x, n-1) % MOD;
}

vector< int > divisor(int n) {
  vector< int > ret;
  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret),greater<int>());
  return (ret);
}

int n;int g[510][510];

void f(int s, int e, int ind){
  if(e-s <= 1)return;
  repd(i,s,(e+s)/2){
    repd(j,(e+s)/2,e){
      g[i][j] = ind;

    }
  }
  //cout << s << " " << e << " " << ind << endl;
  f(s,(e+s)/2,ind+1);
  f((e+s)/2,e, ind+1);
}

signed main(){
  cin>>n;
  f(0,n, 1);
  rep(i,n){
    repd(j,i+1,n){
      cout << g[i][j] << (j == n-1 ? "\n" : " ");
    }
  }
}
