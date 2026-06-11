#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int parent[200005], siz[200005];

int root(int x) {
  if(x==parent[x]) return x;
  else return parent[x] = root(parent[x]);
}

bool same(int x, int y) {
  return root(x)==root(y);
}

void unite(int x, int y) {
  x = root(x);
  y = root(y);
  if(siz[x]<siz[y]) swap(x, y);
  siz[x] += siz[y];
  parent[y] = x;
  return;
}

int main() {
  int N, Q;
  cin>>N>>Q;
  for(int i=0;i<N;++i) {
    parent[i] = i;
    siz[i] = 1;
  }
  int t, u, v;
  vector<bool> arr;
  for(int i=0;i<Q;++i) {
    cin>>t>>u>>v;
    if(t==0) {
      unite(u, v);
    }
    else {
      arr.push_back(same(u, v));
    }
  }
  for(int i=0;i<arr.size();++i) cout<<arr[i]<<endl;
}

