#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
#define outl(x) cout<< (x) << '\n'
#define FAST() cin.tie(0), ios::sync_with_stdio(false)

#define NIL -1
#define LN() cout << '\n'
struct Node{
  int p,l,r;
  Node(): p(NIL), l(NIL), r(NIL){}
};

int N;
Node T[30];

void preorder(int u){
  if(u == NIL)return;
  cout << ' ' << u;
  preorder(T[u].l);
  preorder(T[u].r);
}
void inorder(int u){
  if(u == NIL)return;
  inorder(T[u].l);
  cout << ' ' << u;
  inorder(T[u].r);
}
void postorder(int u){
  if(u == NIL)return;
  postorder(T[u].l);
  postorder(T[u].r);
  cout << ' ' << u;
}

main()
{
  FAST();
  int v,l,r;
  int root;
  cin >> N;
  rep(i,N){
    cin >> v >> l >> r;
    T[v].l = l, T[v].r = r;
    T[l].p = T[r].p = v;
  }
  rep(i,N)
    if(T[i].p == NIL){
      root = i;
      break;
    }

  outl("Preorder");preorder(root);LN();
  outl("Inorder");inorder(root);LN();
  outl("Postorder");postorder(root);LN();
}