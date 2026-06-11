#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <time.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define SQR(X) ((X)*(X))
#define NIL -1

int test = 0;
/* ここからが本編 */
struct Node{
  int r,l,p,d;
};
static struct Node node[100005];
void printChildren(int u)
{
  int c = node[u].l;
  printf(", [");
  if(c != NIL) {
    printf("%d",c);
    c = node[c].r;
    while(c != NIL) {
      printf(", %d",c);
      c = node[c].r;
    }
  }
  puts("]");
}
void setDepth(int u,int p){
  node[u].d = p;
  if(node[u].l != NIL) {
    setDepth(node[u].l,p+1);
  }
  if(node[u].r != NIL) {
    setDepth(node[u].r,p);
  }
}
int main(void)
{
  int i,j,k,l;
  int d;
  int n;
  int id;
  cin >> n;
  rep(i,n) {
    node[i].p = NIL;
    node[i].l = NIL;
    node[i].r = NIL;
  }
  while(cin >> id) {
    int k;
    cin >> k;
    int l;
    if(k) {
      cin >> l;
      node[l].p = id;
      node[id].l = l;
      rep(i,k-1) {
        int c;
        cin >> c;
        node[c].p = id;
        node[l].r = c;
        l = c;
      }
    }
  }
  rep(i,n) {
    if(node[i].p == NIL) setDepth(i,0);
  }
  rep(i,n) {
    printf("node %d:",i);
    printf(" parent = %d",node[i].p);
    printf(", depth = %d",node[i].d);
    if(node[i].p == NIL) {
      printf(", root");
    }
    else if(node[i].l == NIL) {
      printf(", leaf");
    }
    else printf(", internal node");
    printChildren(i);
  }
  return 0;
}