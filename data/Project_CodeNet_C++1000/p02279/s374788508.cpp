#include<iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node{
  int p,l,r;
};

Node T[MAX];
int n, D[MAX];

void print( int s ){
  int i, c;
  cout << "node " << s << ": ";
  cout << "parent = " << T[s].p << ", ";
  cout << "depth = " << D[s] << ", ";

  if( T[s].p == NIL )cout << "root, ";
  else if( T[s].l == NIL )cout << "leaf, ";
  else cout << "internal node, ";

  cout << "[";
  for( i = 0, c = T[s].l ; c != NIL ; i++, c = T[c].r ){
    if( i )cout << ", ";
    cout << c;
  }
  cout << "]" << endl;
}

int rec( int s, int p ){
  D[s] = p;
  if( T[s].r != NIL )rec( T[s].r, p );
  if( T[s].l != NIL )rec( T[s].l, p + 1 );
}

int main( void ){
  int i,j,a,b,c,l,r;
  cin >> n;
  for( i = 0 ; i < n ; i++ ){
    T[i].p = T[i].l = T[i].r = NIL;
  }
  for( i = 0 ; i < n ; i++ ){
    cin >> b >> a;
    for( j = 0 ; j < a ; j++ ){
      cin >> c;
      if( j == 0 )T[b].l = c;
      else T[l].r = c;
      l = c;
      T[c].p = b;
    }
  }
  for( i = 0 ; i < n ; i++ ){
    if( T[i].p == NIL )r = i;
  }

  rec( r, 0 );
  for( i = 0 ; i < n ; i++ )print(i);

  return 0;
}