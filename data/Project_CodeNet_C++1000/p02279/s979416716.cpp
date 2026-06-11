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
  int prnt;
  int k;
  int *c;
};

class RootedTree
{
public:
  int n;
  Node *nd;
  int solve();
  int depth( int id );
  string nodetype( int id );
  int showChildren( int id );
};

int RootedTree::solve()
{
  int id;
  cin >> n;

  nd = new Node[n];

  for ( int i = 0; i < n; ++i )
    {
      nd[i].prnt = -1;
    }

  for ( int i = 0; i < n; ++i )
    {
      cin >> id;
      cin >> nd[id].k;
      
      nd[id].c = new int[nd[id].k];
      
      for ( int j = 0; j < nd[id].k; ++j )
        {
          cin >> nd[id].c[j];
          nd[nd[id].c[j]].prnt = id;
        }
    }

  for ( int i = 0; i < n; ++i )
    {
      cout << "node " << i << ": parent = ";
      cout << nd[i].prnt << ", depth = ";
      cout << depth( i ) << ", ";
      cout << nodetype( i ) << ", ";
      showChildren( i );
      cout << endl;
    }
  
  return 0;
}

int RootedTree::depth( int id )
{
  int ret = 0;
  
  while( (id = nd[id].prnt) != -1 ) ++ret;
  
  return ret;
}

string RootedTree::nodetype( int id )
{
  if ( nd[id].prnt == -1 )
    return "root";

  if ( nd[id].k == 0 )
    return "leaf";
  else
    return "internal node";
}

int RootedTree::showChildren( int id )
{
  if ( nd[id].k == 0 )
    cout << "[]";
  else
    {
      cout << "[";
      for ( int i = 0; i < nd[id].k; ++i )
        {
          if ( i ) cout << ", ";
          cout << nd[id].c[i];
        }
      cout << "]";
    }
          
  return 0;
}

int main()
{

  RootedTree rt;

  rt.solve();

  return 0;
}