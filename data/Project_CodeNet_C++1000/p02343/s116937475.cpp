#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,n) for(i=a;i<n;i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef pair<int,int> pii;

#define MAX_N 100000
int par[MAX_N];                                                                                                           
int rank[MAX_N];

void init(int n){
  for(int i = 0 ; i < n ; i++){
    par[i] = i;
    rank[i] = 0;
  }
}

int find(int x){
  if(par[x] == x) return x;
  else return par[x] = find(par[x]);
}

void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return;
  if(rank[x] == rank[y]) par[x] = y;
  else par[y] =	x;
  if(rank[x] == rank[y]) rank[x]++;
}

bool same(int x, int y){
  return find(x) == find(y);
}

int main(){
  int n,q;
  cin>>n>>q;
  init(n);
  int i,j;
  rep(i,q){
    int p,a,b;
    cin>>p>>a>>b;
    if(p)
      if(same(a,b))cout<<1<<endl;
      else cout<<0<<endl;
    else
      unite(a,b);
  }
}