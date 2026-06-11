#include <iostream>
using namespace std;
#define NIL -1

//左子右兄弟表現の実装
struct Node { int parent, left, right; };
struct Node T[100001];

int D[100001];

//深さを求める
void Depth( int u, int p ) {
  D[u] = p;
  if ( T[u].right != NIL ) {
    Depth( T[u].right, p );
  }
  if ( T[u].left != NIL ) {
    Depth( T[u].left, p + 1 );
  }
}

//出力
void print ( int u ) {
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].parent << ", ";
  cout << "depth = " << D[u] << ", ";

  //根、内部節点、葉を判定し出力する
  if ( T[u].parent == NIL ) cout << "root, ";
  else if ( T[u].left == NIL ) cout << "leaf, ";
  else cout << "internal node, ";
  
  cout << "[";
  
  //子のリストを出力する
  for ( int i = 0, c = T[u].left; c != NIL; i++, c = T[c].right ) {
    if ( i > 0 ) cout << ", ";
    cout << c;
  }
  cout << "]" << endl;
}

int main() {
  int n, k, id, c, l, r;
  cin >> n;
  for ( int i = 0; i < n; i++ ) T[i].parent = T[i].left = T[i].right = NIL; //初期化
  
  //入力
  for ( int i = 0; i < n; i++ ) {
    cin >> id >> k;
    for ( int j = 0; j < k; j++ ) {
      cin >> c;
      if ( j == 0 ) T[id].left = c;
      else T[l].right = c;
      l = c;
      T[c].parent = id;
    }
  }
  
  for ( int i = 0; i < n; i++ ) {
    if ( T[i].parent == NIL ) r = i; 
  }

  Depth(r,0);

  for ( int i = 0; i < n; i++ ) print(i);
  return 0;
}