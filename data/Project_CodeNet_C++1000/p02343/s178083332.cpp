#include <iostream>
#include <algorithm>
#define INF 2147483647
#define MAX_N 100001
using namespace std;
int tree[(1<<18)];
int n,q;

//Segment_tree
void update(int i,int x) {//i = site , x = value
  i+=(n-1);
  tree[i] = x;
  while(i!=0){
    i=(i-1)/2;
    tree[i] = min(tree[i*2+1],tree[i*2+2]);
  }
}

int find(int a ,int b,int M,int L,int R){ 
  if(R<=a || b<=L) return INF;
  if(a<=L && R<=b) return tree[M];
  int nx = (R+L)/2;
  return min(find(a,b,M*2+1,L,nx),find(a,b,M*2+2,nx,R));
}

/*void init(){
  for(int i=0;i<n;i++) update(i,INF);
  }*/

// Union Find
int par[MAX_N]; //parenat
int rank[MAX_N]; //deep

void init(int n){
  for(int i=0;i<n;i++) par[i]=i, rank[i]=0;
}

int find(int x){
  if(par[x] == x) return x;
  return par[x] = find(par[x]);    
}

void unite(int x,int y){
  x = find(x);
  y = find(y);
  if(x == y) return;
  if(rank[x] < rank[y]) par[x] = y;
  else {
    par[y] = x;
    if(rank[x] == rank[y]) rank[x]++;
  }
}

bool same(int x,int y){
  return find(x) == find(y);
}

int main(){
  cin >> n >>q;
  init(n);
  while(q--){
    int com,x,y;
    cin >>com >> x >> y;
    if(com == 0) unite(x,y);
    if(com == 1) cout << same(x,y) <<endl;
  }
  return 0;
}