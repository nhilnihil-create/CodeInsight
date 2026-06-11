#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <sstream>
#include <string>
#include <utility>
#include <map>
#include <memory>
#include <set>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>

using namespace std;

struct Node
{
  Node *parent;
  Node *left;
  Node *right;
  int key;
};

class BStree
{
public:
  Node *root;
  Node *nil;
  int solve();
  int print();
  int insert( Node *z );
  int preorder( Node *nd );
  int inorder( Node *nd );
};

int BStree::solve()
{
  int n;
  cin >> n;
  
  string com;
  int d;
  Node *nd;
  
  for ( auto i = 0; i < n; ++i )
    {
      cin >> com;

      if ( com == "print" )
        print();
      else
        {
          cin >> d;
          nd = new Node;
          nd->key = d;
          nd->parent = nil;
          nd->left = nil;
          nd->right = nil;
          insert( nd );
        }
    }
      
  return 0;
}

int BStree::print()
{
  inorder( root );
  cout << endl;
  preorder( root );
  cout << endl;
  return 0;
}

int BStree::insert( Node *z )
{
  Node *y = nil;
  Node *x = root;

  while ( x != nil )
    {
      y = x;
      if ( z->key < x->key )
        x = x->left;
      else
        x = x->right;
    }

  z->parent = y;

  if ( y == nil )
    root = z;
  else if ( z->key < y->key )
    y->left = z;
  else
    y->right = z;
  
  return 0;
}

int BStree::preorder( Node *nd )
{
  if ( nd == nil )
    return 0;

  cout << " " << nd->key;
  preorder( nd->left );
  preorder( nd->right );
  
  return 0;
}

int BStree::inorder( Node *nd )
{
  if ( nd == nil )
    return 0;

  inorder( nd->left );
  cout << " " << nd->key;
  inorder( nd->right );
  
  return 0;
}

int main()
{

  BStree b;

  b.nil = new Node;
  b.nil->parent = b.nil;
  b.nil->left = b.nil;
  b.nil->right = b.nil;
  b.nil->key = -1;

  b.root = b.nil;
  
  b.solve();

  return 0;
}