#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(a) begin(a),end(a)
typedef long long ll;
typedef pair<int,int> P;
const int inf=1e+9;
const ll mod=1000000007;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
ll gcd(ll a, ll b){
  if (b==0) return a;
  else return gcd(b,a%b);
}
int cans(bool f){
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

#define NIL -1
#define MAX 100005

struct Node{
  int p,l,r;
};

Node T[MAX];
int n,D[MAX];

void print(int u) {
  int i,c;
  cout << "node " << u << ": " ;
  cout << "parent" << " = " << T[u].p << ", ";
  cout << "depth" << " = " << D[u] << ", ";
  if(T[u].p == NIL) cout << "root, ";
  else if(T[u].l == NIL) cout << "leaf, ";
  else cout << "internal node, ";

  cout << "[";
  for(int i=0, c=T[u].l; c != NIL; i++, c=T[c].r) {
    if(i) cout << ", ";
    cout << c;
  }
  cout << "]" << endl;;
}



void rec(int u, int p) {
  D[u] = p;
  if(T[u].r != NIL) rec(T[u].r,p);
  if(T[u].l != NIL) rec(T[u].l,p+1);
}


int main() {
  int c,l,r;
  int N;
  cin >> N;
  rep(i,N) T[i].l = T[i].r = T[i].p = NIL;
  rep(i,N) {
    int v,d;
    cin >> v >> d;
    rep(i,d) {
      cin >> c;
      if(i == 0) T[v].l = c;
      else T[l].r = c;
      l = c;
      T[c].p = v;
    }
  }
  
  rep(i,N) if(T[i].p == NIL) r = i;
  rec(r,0);

  rep(i,N) print(i);

  return 0;
}

